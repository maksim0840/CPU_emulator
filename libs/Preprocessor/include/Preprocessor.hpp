#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

struct incorrect_number_of_line_arguments {
	const int line;
};

namespace proc {


// template <typename T>
class Preprocessor {

public:
	enum class Command {
		BEGIN , END, PUSH, POP, PUSHR, POPR, ADD,
		SUB, MUL, DIV, OUT, IN, JMP, JEQ, JNE, 
		JA, JAE, JB, JBE, CALL, RET, TAG
	};

	struct command_line {
		Command type;
		int value;
	};

	struct command_info {
		int variables;
		Command type;
	};

	struct function_range {
		int tag_ind;
		int ret_ind;
	};

	typedef std::vector<std::string> stringvec;
	typedef std::vector<command_line> commands_vec;
	typedef std::unordered_map<std::string, function_range> functions_map;

	void fill_params_from_string_commands(const std::vector<stringvec>&, commands_vec&, functions_map&);

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

	void get_value_from_string(int&, const stringvec&);

	void get_command(const stringvec&, const int, commands_vec&);

	void get_function(const stringvec&, const int, commands_vec&, functions_map&);
};


}
