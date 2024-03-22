#include <iostream>
#include "libs/Parser/src/Parser.cpp"
#include "libs/CPU/src/CPU.cpp" // Stack and Preprocessor libs connected to CPU lib
#include <vector>
#include <string>

struct incorrect_number_of_console_arguments {
	const int input_arguments;
};

int main(int argc, char* argv[]) {
	if (argc != 2) {
		throw incorrect_number_of_console_arguments(argc);
	}


	std::string file_name = argv[1];
	input::Parser parser;
	multivec_strings parser_commands = parser.parse_file(file_name);

	preproc::Preprocessor::commands_vec preprocessor_commands;
	preproc::Preprocessor::redirects_map preprocessor_redirects;
	preproc::Preprocessor preprocessor;
	preprocessor.fill_params_from_string_commands(
		parser_commands, preprocessor_commands, preprocessor_redirects);

	storage::Stack<int> stack;
	proc::CpuStarter<int> cpu;
	cpu.start(preprocessor_commands, preprocessor_redirects, stack);

	for (auto out:cpu.get_result()) {
		std::cout << out << '\n';
	}

	return 0;
}
