#include "../include/Preprocessor.hpp"


namespace proc {


// template <typename T>
void Preprocessor::fill_params_from_string_commands(const std::vector<stringvec>& parser_commands, commands_vec& commands, functions_map& functions) {
	for (int i = 0; i < parser_commands.size(); ++i) {
		const stringvec& line_args = parser_commands[i];
		auto iter = command_classification.find(line_args[1]); // find by command name

		if (iter != command_classification.end()) { // default commands
			get_command(line_args, i, commands);
		}
		else { // returns and tags
			get_function(line_args, i, commands, functions);
		}
	} 

}

void Preprocessor::get_value_from_string(int& res, const stringvec& line_args) {
	if (line_args.size() > 2) {
		res = std::stoi(line_args[2]);
	}
}

void Preprocessor::get_command(const stringvec& line_args, const int ind, commands_vec& commands) {
	if (line_args.size() > (command_classification[line_args[1]].variables + 2)) {
		throw incorrect_number_of_line_arguments(std::stoi(line_args[0]));
	}
	
	int value; // empty value
	get_value_from_string(value, line_args);
	commands.push_back({command_classification[line_args[1]].type, value});
}

void Preprocessor::get_function(const stringvec& line_args, const int ind, commands_vec& commands, functions_map& functions) {
	if (line_args.size() != 2) {
		throw incorrect_number_of_line_arguments(std::stoi(line_args[0]));
	}

	int value; // empty value
	if (line_args[1] == "ret") { // return
		commands.push_back({Command::RET, value});
		functions[line_args[1]].ret_ind = ind;
	}
	else { // tag
		commands.push_back({Command::TAG, value});
		functions[line_args[1]].tag_ind = ind;
	}
}


}


