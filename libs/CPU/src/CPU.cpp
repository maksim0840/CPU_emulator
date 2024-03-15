#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include "../../Stack/src/Stack.cpp"
#include "../../Stack/include/Stack.hpp"

struct unknown_command {
	const std::string command;
	const std::string line;
};

struct incorrect_args_value_in_command {
	const std::string command;
	const std::string line;
};

typedef std::vector<std::string> stringvec;
	
namespace commands {


class CPU {

private:
	void BEGIN(const stringvec& line_args) {
		allow_command_execution = true;
	}

	void END(const stringvec& line_args) {
		allow_command_execution = false;
	}

	void PUSHR(const stringvec& line_args) {

	}

	void POPR(const stringvec& line_args) {

	}

	void ADD(const stringvec& line_args) {

	}

	void SUB(const stringvec& line_args) {

	}

	void MUL(const stringvec& line_args) {

	}

	void DIV(const stringvec& line_args) {

	}

	void OUT(const stringvec& line_args) {

	}

	void IN(const stringvec& line_args) {

	}

public:
	bool allow_command_execution = false;

	template <typename T>
	void execute_commands(std::vector<stringvec> commands_vec, storage::Stack<T>& stack) {
		std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> allowed_commands = {
			{"begin", [this](const stringvec& line_args) {this->BEGIN(line_args);}},
			{"end", [this](const stringvec& line_args) {this->END(line_args);}},
			{"pushr", [this](const stringvec& line_args) {this->PUSHR(line_args);}},
			{"popr", [this](const stringvec& line_args) {this->POPR(line_args);}},
			{"add", [this](const stringvec& line_args) {this->ADD(line_args);}},
			{"sub", [this](const stringvec& line_args) {this->SUB(line_args);}},
			{"mul", [this](const stringvec& line_args) {this->MUL(line_args);}},
			{"div", [this](const stringvec& line_args) {this->DIV(line_args);}},
			{"out", [this](const stringvec& line_args) {this->OUT(line_args);}},
			{"in", [this](const stringvec& line_args) {this->IN(line_args);}},
		};
		
		std::unordered_set<std::string> no_values_commands = {
			"begin", "end", "pop", "add", "sub", "mul", "div", "out", "in", "ret"
		};

		for (const stringvec& line_args : commands_vec) {
			// does this command exist
			auto iter1 = allowed_commands.find(line_args[1]);
			if (iter1 == allowed_commands.end()) {
				throw unknown_command(line_args[1], line_args[0]);
			}

			// does this command correct
			auto iter2 = no_values_commands.find(line_args[1]);
			if ((iter2 == no_values_commands.end() && line_args.size() == 2) || \
				(iter2 != no_values_commands.end() && line_args.size() == 3)) {
				throw incorrect_args_value_in_command(line_args[1], line_args[0]);
			}

			allowed_commands[line_args[1]](line_args);
		}


	}

};


}