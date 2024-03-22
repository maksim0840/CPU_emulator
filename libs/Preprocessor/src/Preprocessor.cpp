#include "../include/Preprocessor.hpp"


namespace preproc {


// template <typename T>
void Preprocessor::fill_params_from_string_commands(const std::vector<stringvec>& parser_commands, commands_vec& commands, redirects_map& redirects) {
	for (int i = 0; i < parser_commands.size(); ++i) {
		const stringvec& line_args = parser_commands[i];
		auto iter = command_classification.find(line_args[1]); // find by command name

		if (iter != command_classification.end()) { // default commands
			get_command(line_args, i, commands);
		}
		else { // returns, tags and functions
			get_redirect(line_args, i, commands, redirects);
		}
	} 

}

void Preprocessor::get_command(const stringvec& line_args, const int ind, commands_vec& commands) {
	if (line_args.size() > (command_classification[line_args[1]].variables + 2)) {
		throw incorrect_number_of_line_arguments(std::stoi(line_args[0]));
	}
	
	std::string value = "";
	if (line_args.size() > 2) {
		value = line_args[2];
	}
	commands.push_back({command_classification[line_args[1]].type, value});
}

void Preprocessor::get_redirect(const stringvec& line_args, const int ind, commands_vec& commands, redirects_map& redirects) {
	if (line_args.size() != 2) {
		throw incorrect_number_of_line_arguments(std::stoi(line_args[0]));
	}

	std::string value = ""; // empty value
	if (line_args[1] == "ret") { // return
		commands.push_back({Command::RET, value});
		redirects[cur_func_name].ret_ind = ind;
	}
	else { // tag or function
		if (line_args[1].size() > 0 && line_args[1].back() == ':') {
			cur_func_name = line_args[1];
		}
		commands.push_back({Command::REDIRECT, value});
		redirects[line_args[1]].start_ind = ind;
	}
}


}


