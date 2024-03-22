#include "../include/Starter.hpp"

namespace run {


template <typename T>
void Starter<T>::execute(int argc, char* argv[]) {
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

	storage::Stack<T> stack;
	proc::CpuStarter<T> cpu;
	cpu.start(preprocessor_commands, preprocessor_redirects, stack);
	result = cpu.get_result();

}

template <typename T>
std::vector<T> Starter<T>::get_result() {
	return result;
}


};