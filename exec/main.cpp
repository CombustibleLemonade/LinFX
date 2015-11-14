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

std::string replace_all(std::string s, const char* a, const char* b);
bool has_substring(std::string s, const char* sub);

class Function{
	std::string name; // Name of the function
	std::string return_type; // Type it returns
	std::vector<std::string> arguments; // Types of the arguments

public:
	static std::string prefix;
	Function(std::string code){
		std::stringstream codestream(code);
		std::getline(codestream, return_type, ' ');
		std::getline(codestream, name, '(');
		name = replace_all(name, " ", "");

		if (has_substring(name, "*")){ // Our return type is actually a pointer
			name.erase(name.find("*"), 1); // Remove it from the name
			return_type += "*"; // And add it to the return type
		}
		if (name.empty()){
			std::getline(codestream, name, '(');
		}
		if (has_substring(name, "*")){ // * is from the function pointer, not the return type
			name.erase(name.find("*"), 1); // Just delete it and don't add it to the return type
		}
		std::string segment;
		while(std::getline(codestream, segment, ',')){
			// Cut off spaces in the beginning
			while(segment.find(" ") == 0){
				segment.erase(0, 1);
			}
			// Cut off after spaces
			if (has_substring(segment, "*")){
				segment.erase(segment.find("*") + 1, std::string::npos);
			}
			else if (has_substring(segment, " ")){
				segment.erase(segment.find(" "), std::string::npos);
			}

			// Only the type is left
			if (!segment.empty() && !has_substring(segment, "void")){
				arguments.push_back(segment);
			}
		}
	}

	std::string create_hooker(){
		std::string hooker = "Hooker<" + return_type;
		for(int i = 0; i < arguments.size(); i++){
			hooker += ", ";
			hooker += arguments[i];
		}
		hooker += "> " + prefix + name + "(\"" + name + "\");";

		return hooker;
	}
};

std::string Function::prefix = "l";

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

std::string replace_all(std::string s, const char* a, const char* b){
	std::size_t pos = s.find(a);
	while(pos != std::string::npos){
		s.replace(pos, strlen(a), b);
		pos = s.find(a);
	}
	return s;
}

bool has_substring(std::string s, const char* sub){
	return s.find(sub) != std::string::npos;
}

std::string delete_all_between(std::string s, const char* a, const char* b){
	std::size_t a_pos = s.find(a);
	std::size_t b_pos = s.find(b, a_pos);

	while (has_substring(s, a) && has_substring(s, b)) {
		s.replace(a_pos, static_cast<int>(b_pos-a_pos) + strlen(b), "");
		std::size_t a_pos = s.find(a);
		std::size_t b_pos = s.find(b, a_pos);
	}
	return s;
}

// Will parse a certain segment and return only the function. Returns "" if there is no function
std::string parse_segment_to_function(std::string segment){
	std::string s = segment;

	if (!has_substring(s, ";")) return "";
	if (!has_substring(s, "(") || !has_substring(s, ")")) return "";
	if (has_substring(s, "typedef")) return "";
	if (has_substring(s, "return")) return "";
	if (has_substring(s, "struct")) return "";
	if (has_substring(s, "[") || has_substring(s, "]")) return "";

	s = delete_all_between(s, "__att", ")) ");
	s = delete_all_between(s, "__att", "));");

	if (!has_substring(s, "(") || !has_substring(s, ")")) return "";

	s = replace_all(s, ";", "");
	s = replace_all(s, "  ", " ");
	s = replace_all(s, "extern ", "");
	s = replace_all(s, "const ", "");
	s = replace_all(s, "* ", "");
	return s;
}

std::string create_injection_header(const char* source_header){
	// Create gcc command to call
	std::string source_header_str = std::string(source_header);
	std::string command = "gcc -E ";
	// Call command
	std::stringstream code(exec((command + source_header_str).c_str()));

	// Separate all of the functions out of the string
	std::string segment;
	std::vector<Function> functions;
	while(std::getline(code, segment, '\n')){
		std::string function = parse_segment_to_function(segment);
		if (!function.empty()){
			functions.push_back(Function(function));
		}
	}

	std::string output = "";
	output += "#include \"";
	output += source_header;
	output += "\"\n";
	for (Function o : functions){
		output += o.create_hooker() + "\n";
	}
	return output;
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


