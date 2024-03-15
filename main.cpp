#include <iostream>
#include "libs/Parser/src/Parser.cpp"
#include "libs/CPU/src/CPU.cpp" // Stack lib connected to CPU lib
#include <vector>
#include <string>

struct incorrect_number_of_console_arguments {
	const int input_arguments;
};

int main(int argc, char* argv[]) {
	if (argc != 2) {
		throw incorrect_number_of_console_arguments(argc);
	}

	storage::Stack<int> stack;
	input::Parser parser;
	commands::CPU<int> cpu;

	std::string file_name = argv[1];
	std::vector<std::vector<std::string>> commands_vec = parser.parse_file(file_name);
	// cpu.cpu_starter(commands_vec, stack);
	
	// for (const auto& out : cpu.get_output()) {
	// 	std::cout << out << '\n';
	// }

	// print scanned commands
	for (auto vec : commands_vec) {
		for (auto str : vec) {
			std::cout << str << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
