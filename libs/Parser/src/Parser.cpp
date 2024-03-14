#include <iostream>
#include <fstream>
#include <string>


/* ERRORS */


struct file_opening_error {
	const char* file_name;
};

struct incorrect_number_of_console_arguments {
	const int input_arguments;
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


/* FUNCTIONS */

// Allowed in naming symbols
bool is_naming_allowed(const char sym) {
	return ((97 <= sym && sym <= 122) || \
		(47 <= sym && sym <= 57) || (sym == '_'));
}

// Skip ' ' and '\t' symbols, return last read symbol
char skip_emptiness(std::ifstream& file, const int line) {
	char sym;
	// Skip symbols ' ' and '\t'
	while (file.get(sym) && (sym == ' ' || sym == '\t'));

	if (!(is_naming_allowed(sym) || sym == '\n' || sym == '\0')) {
		throw unexpected_symbol(sym, line);
	}

	return sym;
}

bool parse_line(std::ifstream& file, const int line) {
	char sym;
	char first_sym = skip_emptiness(file, line);

	if (first_sym == '\n') { // empty line
		return true;
	}
	else if (first_sym == '\0') {
		return false;
	}

	std::string command;
	std::string value;
	command.reserve(10);
	value.reserve(10);

	command.push_back(first_sym);
	std::string* cur_filling = &command;
	int separators = 0;

	// Read command
	while (file.get(sym)) {
		switch(sym) {
		case ' ':
			++separators;
			cur_filling = &value;
			if (separators > 1) {
				throw too_many_line_separators_for_2_arguments_received(line);
			}
			break;
		case '\0':
		case '\n':
			if (command.empty() || value.empty()) {
				throw missing_line_arguments(line);
			}
			// COMPLETE THE LINE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			std::cout << "Command:" << command << " Value:" << value << '\n';
			return true;
		default:
			if (is_naming_allowed(sym)) {
				(*cur_filling).push_back(sym);
				break;
			}
			throw unexpected_symbol(sym, line);
		}
	}
	return false;
}

void parse_file_starter(const char* file_name) {
	std::ifstream file;
	file.open(file_name);

	if (!file.is_open()) {
		throw file_opening_error(file_name);
	}

	int line = 0;

	while(parse_line(file, line)) {
		++line;
	}

	file.close();
}


/* CONSOLE INPUT */


int main(int argc, char* argv[]) {

	if (argc != 2) {
		throw incorrect_number_of_console_arguments(argc);
	}

	parse_file_starter(argv[1]);

	return 0;
}
