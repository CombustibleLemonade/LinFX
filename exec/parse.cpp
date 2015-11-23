#include <iostream>
#include <stdlib.h>
#include <dlfcn.h>

#include <string>
#include <cstring>

#include <vector>
#include <cstdio>
#include <memory>
#include <sstream>
#include <fstream>

#include <initializer_list>

void replace_all(std::string& s, const char* a, const char* b){
	std::size_t pos = s.find(a);
	while(pos != std::string::npos){
		s.replace(pos, strlen(a), b);
		pos = s.find(a);
	}
}

std::string parse_between(std::string& s, char a, char b, size_t starting_pos = -1){
	int deep = 0;
	std::string ret = "";

	for (size_t i = 0; i < s.size(); i++){
		while(i < s.size()){
			char c = s[i];
			if(c == a){
				deep++;
				s.erase(i, 1);
			}
			else if (c == b){
				deep--;
				s.erase(i, 1);
				if (starting_pos != -1 && deep == 0){
					return ret;
				}
			}
			else if (deep > 0){
				ret += c;
				s.erase(i, 1);
			}
			else {break;}
		}
	}
	return ret;
}

std::string parse_squirly_brackets(std::string& s, size_t starting_pos = -1){
	return parse_between(s, '{', '}', starting_pos);
}

std::string parse_parentices(std::string& s, size_t starting_pos = -1){
	return parse_between(s, '(', ')', starting_pos);
}

std::string parse_semicolon_part(std::string part){
	if (part.find("(*") != std::string::npos) return "";
	if (part.find("typedef") != std::string::npos) return "";
	if (part.find("{") != std::string::npos) return "";
	if (part.find("}") != std::string::npos) return "";

	size_t attribute = part.find("__attribute__");
	if (attribute != std::string::npos){
		parse_parentices(part, attribute);
	}
	replace_all(part, "__attribute__", "");
	replace_all(part, "extern", "");

	while (part.find("((") != std::string::npos){
		parse_between(part, '(', ')', part.find("(("));
	}

	if (part.find("(") == std::string::npos) return "";
	if (part.find(")") == std::string::npos) return "";

	replace_all(part, "  ", " ");

	if (part[0] == ' '){
		part.erase(0, 1);
	}

	return part;
}

std::string get_type(std::string& from){
	while (from[0] == ' '){
		from.erase(0, 1);
	}

	replace_all(from, "struct", "");

	std::stringstream stream(from);
	std::string streamcache;
	std::string type = "";
	while (std::getline(stream, streamcache, ' ')){
		type += streamcache;
		if (streamcache.find("unsigned") == std::string::npos &&
				streamcache.find("const") == std::string::npos){
			break;
		}
		type += " ";
	}

	// Delete after parenteces, comma's or spaces.
	std::string no_other_types = from;
	size_t par_pos = no_other_types.find("(");
	if (par_pos != std::string::npos){
		no_other_types.erase(par_pos, std::string::npos);
	}

	size_t  comma_pos = no_other_types.find(",");
	if (comma_pos != std::string::npos){
		no_other_types.erase(comma_pos, std::string::npos);
	}

	size_t  space_pos = no_other_types.find(" ");
	if (space_pos != std::string::npos){
		no_other_types.erase(0, space_pos);
	} else {
		no_other_types = "";
	}

	if (no_other_types.find("*") != std::string::npos){
		type += "*";
	}

	return type;
}

std::string create_hooker(std::string function){


	// Get type, name, and arguments of function
	std::string type = get_type(function);

	std::string argument_str = parse_parentices(function);
	std::stringstream stream(argument_str);
	std::string streamcache;
	std::vector<std::string> arguments;
	while (std::getline(stream, streamcache, ',')){
		arguments.push_back(streamcache);
	}

	for (long i = 0; i < arguments.size(); i++){
		if (arguments[i].find("void") == std::string::npos){
			arguments[i] = get_type(arguments[i]);
		} else {
			arguments.erase(arguments.begin() + i);
			i--;
		}
	}

	function = std::string(function.rbegin(), function.rend());
	std::stringstream funcstr(function);
	std::getline(funcstr, function, ' ');
	function = std::string(function.rbegin(), function.rend());

	replace_all(function, " ", "");
	while (function[0] == '*'){
		type += "*";
		function.erase(0, 1);
	}

	// Create hooker
	std::string hooker = "Hooker<";
	hooker += type;
	for (std::string i : arguments){
		hooker += ", ";
		hooker += get_type(i);
	}
	hooker += "> l";
	hooker += function;
	hooker += "(\"";
	hooker += function;
	hooker += "\");";

	if(function.empty()) return "";


	return hooker;
}

std::string exec(const char* cmd) {
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) return "ERROR";
	char buffer[128];
	std::string result = "";
	while (!feof(pipe.get())) {
		if (fgets(buffer, 128, pipe.get()) != NULL)
			result += buffer;
	}

	return result;
}

// Creates the output code
std::string create_injection_header(std::string s){
	std::string code = exec(("gcc -E " + s).c_str());

	std::string functions = "";

	size_t i = 0;
	std::string line = "";
	std::string semicolon_part = "";
	while (i < code.size()){
		char c = code[i];
		if (c == '#'){
			code.erase(i, code.find('\n'));
			line = ""; // Reset our line
			semicolon_part = ""; // Reset our semicolon business
		} else if (c == '\n'){
			line = "";
			semicolon_part += " ";
			code.erase(0, 1);
		} else if (c == ';'){
			semicolon_part = parse_semicolon_part(semicolon_part);
			if (!semicolon_part.empty()) functions += semicolon_part + "\n";
			semicolon_part = "";
			line += c;
			code.erase(0, 1);
		} else {
			semicolon_part += c;
			line += c;
			code.erase(0, 1);
		}
	}

	std::string hookers = "";
	std::stringstream stream(functions);
	std::string streamcache;
	while (std::getline(stream, streamcache, '\n')){
		hookers += create_hooker(streamcache) + '\n';
	}


	return hookers;
}

int main(int argc, char* argv[]) {
	// Get the target directory
	const char* target = "headerfile.h";
	if (argc > 1){
		target = "/headerfile.h";
		target = strcat(argv[1], target);
	}
	//Get the parsed code
	std::ofstream outputFile(target);
	outputFile << create_injection_header("/usr/include/GL/glx.h");

	return 0;
}
