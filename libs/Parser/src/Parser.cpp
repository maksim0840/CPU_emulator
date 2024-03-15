#include "../include/Parser.hpp"

namespace input {


/* PRIVATE METHODS */


char Parser::to_low_register(const char sym) {
	if (65 <= sym && sym <= 90) {
		return sym + 32;
	}
	return sym;
}

// Allowed in naming symbols
bool Parser::is_naming_allowed(const char sym) {
	return ((97 <= sym && sym <= 122) || (65 <= sym && sym <= 90) || \
		(48 <= sym && sym <= 57) || (sym == '_'));
}

bool Parser::parse_line(std::ifstream& file, const int line, multivec_strings& commands_vec) {
	char sym = '\0';
	while (file.get(sym) && (sym == ' ' || sym == '\t')); // skip emptiness
	std::vector<std::string> line_args = {std::to_string(line)}; // the first arg always = line num

	if (sym == '\n') { // empty line
		return true;
	}

	std::string arg;
	arg.push_back(to_low_register(sym));

	// Read command
	while (file.get(sym)) {
		switch(sym) {
		case ' ':
			line_args.push_back(arg);
			arg.clear();
			break;
		case '\0':
		case '\n':
			line_args.push_back(arg);
			commands_vec.push_back(line_args);
			return true;
		default:
			arg.push_back(to_low_register(sym));
		}
	}
	return false;
}


/* PUBLIC METHODS */
	

multivec_strings Parser::parse_file(const std::string& file_name) {
	std::ifstream file;
	file.open(file_name);

	if (!file.is_open()) {
		throw file_opening_error(file_name);
	}

	int line = 0;
	multivec_strings commands_vec; 

	while(parse_line(file, line, commands_vec)) {
		++line;
	}

	file.close();
	return commands_vec;
}


}