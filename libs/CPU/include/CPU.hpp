#pragma once
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

template <typename T>
class CPU {	
	private:
		std::vector<stringvec> cpu_commands_vec;
		storage::Stack<T> cpu_stack;
		std::unordered_map<std::string, T> cpu_registers;
		std::vector<T> output;

		bool allow_command_execution = false;
		std::unordered_map<std::string, std::vector<int>> tags;
		std::string cur_tag_building = "";

		std::unordered_map<std::string, std::function<void(const int)>> allowed_commands = {
			{"begin", [this](const int cur_command) {this->BEGIN(cur_command);}},
			{"end", [this](const int cur_command) {this->END(cur_command);}},
			{"push", [this](const int cur_command) {this->PUSH(cur_command);}},
			{"pop", [this](const int cur_command) {this->POP(cur_command);}},
			{"pushr", [this](const int cur_command) {this->PUSHR(cur_command);}},
			{"popr", [this](const int cur_command) {this->POPR(cur_command);}},
			{"add", [this](const int cur_command) {this->ADD(cur_command);}},
			{"sub", [this](const int cur_command) {this->SUB(cur_command);}},
			{"mul", [this](const int cur_command) {this->MUL(cur_command);}},
			{"div", [this](const int cur_command) {this->DIV(cur_command);}},
			{"out", [this](const int cur_command) {this->OUT(cur_command);}},
			{"in", [this](const int cur_command) {this->IN(cur_command);}},
			{"ret", [this](const int cur_command) {this->RET(cur_command);}},
		};

		std::unordered_set<std::string> no_values_commands = {
			"begin", "end", "pop", "add", "sub", "mul", "div", "out", "in", "ret"
		};

		void BEGIN(const int);
		void END(const int);
		void PUSH(const int);
		void POP(const int);
		void PUSHR(const int);
		void POPR(const int);
		void ADD(const int);
		void SUB(const int);
		void MUL(const int);
		void DIV(const int);
		void OUT(const int);
		void IN(const int);
		void JMP(const int);
		void RET(const int);

		bool does_this_command_exist(const int);
		void does_this_command_correct(const int);
		void execute_commands(const int, const int);

	public:
		void cpu_starter(const std::vector<stringvec>&, storage::Stack<T>&);
		std::vector<T> get_output();
};


}