
#include <fstream>
#include "../../CPU/src/CPU.cpp"
#include "../../CPU/include/CPU.hpp"
#include <vector>
#include <array>


typedef std::vector<std::vector<std::string>> multivec_strings;


/* ERRORS */


struct file_opening_error {
	const char* file_name;
};

struct unexpected_symbol {
	const char sym;
	const int line;
};

struct missing_line_arguments {
	const int line;
};

struct too_many_line_separators_for_2_arguments_received {
	const int line;
};


namespace input {


class Parser {
private:
	char to_low_register(const char sym) {
		if (65 <= sym && sym <= 90) {
			return sym + 32;
		}
		return sym;
	}

	// Allowed in naming symbols
	bool is_naming_allowed(const char sym) {
		return ((97 <= sym && sym <= 122) || (65 <= sym && sym <= 90) || \
			(48 <= sym <= 57) || (sym == '_'));
	}

	// Skip ' ' and '\t' symbols, return last read symbol
	char skip_emptiness(std::ifstream& file, const int line) {
		char sym = '\0';
		// Skip symbols ' ' and '\t'
		while (file.get(sym) && (sym == ' ' || sym == '\t'));

		if (!(is_naming_allowed(sym) || sym == '\n' || sym == '\0')) {
			throw unexpected_symbol(sym, line);
		}

		return sym;
	}

	bool parse_line(std::ifstream& file, const int line, multivec_strings& commands_vec) {
		char sym = '\0';
		char first_sym = skip_emptiness(file, line);
		std::vector<std::string> line_args = {std::to_string(line)}; // the first arg always = line num

		if (first_sym == '\n') { // empty line
			return true;
		}

		std::string arg;
		arg.push_back(first_sym);

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
				if (is_naming_allowed(sym)) {
					arg.push_back(to_low_register(sym));
					break;
				}
				throw unexpected_symbol(sym, line);
			}
		}
		return false;
	}

public:
	multivec_strings parse_file(const char* file_name) {
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


};


}