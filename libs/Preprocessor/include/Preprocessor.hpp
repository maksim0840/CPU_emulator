#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

struct incorrect_number_of_line_arguments {
	const int line;
};

namespace preproc {


// template <typename T>
class Preprocessor {

public:
	enum class Command {
		BEGIN , END, PUSH, POP, PUSHR, POPR, ADD,
		SUB, MUL, DIV, OUT, IN, JMP, JEQ, JNE, 
		JA, JAE, JB, JBE, CALL, RET, REDIRECT
	};

	struct command_line {
		Command type;
		std::string value;
	};

	struct command_info {
		int variables;
		Command type;
	};

	struct redirect_range {
		int start_ind;
		int ret_ind;
	};

	typedef std::vector<std::string> stringvec;
	typedef std::vector<command_line> commands_vec;
	typedef std::unordered_map<std::string, redirect_range> redirects_map;

	void fill_params_from_string_commands(const std::vector<stringvec>&, commands_vec&, redirects_map&);

private:
	std::unordered_map<std::string, command_info> command_classification = {
		{"begin", {0, Command::BEGIN}},
		{"end", {0, Command::END}},
		{"push", {1, Command::PUSH}},
		{"pop", {0, Command::POP}},
		{"pushr", {1, Command::PUSHR}},
		{"popr", {1, Command::POPR}},
		{"add", {0, Command::ADD}},
		{"sub", {0, Command::SUB}},
		{"mul", {0, Command::MUL}},
		{"div", {0, Command::DIV}},
		{"out", {0, Command::OUT}},
		{"in", {0, Command::IN}},
		{"jmp", {1, Command::JMP}},
		{"jeq", {1, Command::JEQ}},
		{"jne", {1, Command::JNE}},
		{"ja", {1, Command::JA}},
		{"jae", {1, Command::JAE}},
		{"jb", {1, Command::JB}},
		{"jbe", {1, Command::JBE}},
		{"call", {1, Command::CALL}},
	};

	std::string cur_func_name = "";

	void get_command(const stringvec&, const int, commands_vec&);

	void get_redirect(const stringvec&, const int, commands_vec&, redirects_map&);
};


}
