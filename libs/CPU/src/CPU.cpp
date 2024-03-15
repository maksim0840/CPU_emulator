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

struct no_such_register {
	const std::string cpu_register;
	const std::string line;
};

typedef std::vector<std::string> stringvec;
	
namespace commands {


class CPU {

private:
	template <typename T>
	void BEGIN(const stringvec& line_args, storage::Stack<T>& stack) {
		allow_command_execution = true;
	}

	template <typename T>
	void END(const stringvec& line_args, storage::Stack<T>& stack) {
		allow_command_execution = false;
	}

	template <typename T>
	void PUSH(const stringvec& line_args, storage::Stack<T>& stack) {
		stack.push(std::stoi(line_args[2]));
	}

	template <typename T>
	void POP(const stringvec& line_args, storage::Stack<T>& stack) {
		stack.pop();
	}

	template <typename T>
	void PUSHR(const stringvec& line_args, storage::Stack<T>& stack) {
		auto iter = cpu_registers.find(line_args[2]);
		if (iter == cpu_registers.end()) {
			throw no_such_register(line_args[2], line_args[0]);
		}
		stack.push(cpu_registers[line_args[2]]);
	}

	template <typename T>
	void POPR(const stringvec& line_args, storage::Stack<T>& stack) {
		cpu_registers[line_args[2]] = stack.top();
		stack.pop();
	}

	template <typename T>
	void ADD(const stringvec& line_args, storage::Stack<T>& stack) {
		T buff = stack.top();
		stack.pop();
		T sum = buff + stack.top();
		stack.push(buff);
		stack.push(sum);
	}

	template <typename T>
	void SUB(const stringvec& line_args, storage::Stack<T>& stack) {
		T buff = stack.top();
		stack.pop();
		T sum = buff - stack.top();
		stack.push(buff);
		stack.push(sum);
	}

	template <typename T>
	void MUL(const stringvec& line_args, storage::Stack<T>& stack) {
		T buff = stack.top();
		stack.pop();
		T sum = buff * stack.top();
		stack.push(buff);
		stack.push(sum);
	}

	template <typename T>
	void DIV(const stringvec& line_args, storage::Stack<T>& stack) {
		T buff = stack.top();
		stack.pop();
		T sum = buff / stack.top();
		stack.push(buff);
		stack.push(sum);
	}

	template <typename T>
	void OUT(const stringvec& line_args, storage::Stack<T>& stack) {
		std::cout << stack.top();
		stack.pop();
	}

	template <typename T>
	void IN(const stringvec& line_args, storage::Stack<T>& stack) {
	}

	template <typename T>
	void JMP(const stringvec& line_args, storage::Stack<T>& stack) {
		tags[cur_tag_building][1] = std::stoi(line_args[0]);
		cur_tag_building.clear();
	}

	template <typename T>
	void RET(const stringvec& line_args, storage::Stack<T>& stack) {
		tags[cur_tag_building][1] = std::stoi(line_args[0]);
		cur_tag_building.clear();
	}

public:
	bool allow_command_execution = false;
	std::unordered_map<std::string, int> cpu_registers;
	std::unordered_map<std::string, std::vector<int>> tags;
	std::string cur_tag_building = "";

	template <typename T>
	void execute_commands(std::vector<stringvec> commands_vec, storage::Stack<T>& stack) {
		std::unordered_map<std::string, std::function<void(const stringvec&, storage::Stack<T>&)>> allowed_commands = {
			{"begin", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->BEGIN(line_args, stack);}},
			{"end", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->END(line_args, stack);}},
			{"push", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->PUSH(line_args, stack);}},
			{"pop", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->POP(line_args, stack);}},
			{"pushr", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->PUSHR(line_args, stack);}},
			{"popr", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->POPR(line_args, stack);}},
			{"add", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->ADD(line_args, stack);}},
			{"sub", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->SUB(line_args, stack);}},
			{"mul", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->MUL(line_args, stack);}},
			{"div", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->DIV(line_args, stack);}},
			{"out", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->OUT(line_args, stack);}},
			{"in", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->IN(line_args, stack);}},
			{"ret", [this](const stringvec& line_args, storage::Stack<T>& stack) {this->RET(line_args, stack);}},
		};

		std::unordered_set<std::string> no_values_commands = {
			"begin", "end", "pop", "add", "sub", "mul", "div", "out", "in", "ret"
		};

		int i = 0;
		for (const stringvec& line_args : commands_vec) {
			// does this command exist
			auto iter1 = allowed_commands.find(line_args[1]);
			if (iter1 == allowed_commands.end()) {
				if (line_args.size() == 2) {
					cur_tag_building = line_args[1];
					tags[line_args[1]] = {i, -1};
				}
				else {
					throw unknown_command(line_args[1], line_args[0]);
				}
			}

			// does this command correct
			auto iter2 = no_values_commands.find(line_args[1]);
			if ((iter2 == no_values_commands.end() && line_args.size() == 2) || \
				(iter2 != no_values_commands.end() && line_args.size() == 3)) {
				throw incorrect_args_value_in_command(line_args[1], line_args[0]);
			}

			allowed_commands[line_args[1]](line_args, stack);
			++i;
		}


	}

};


}