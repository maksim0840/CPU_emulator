#include "../include/CPU.hpp"
namespace commands {


/* PRIVATE METHODS */

template <typename T>
void CPU<T>::BEGIN(const int cur_command) {
	allow_command_execution = true;
}

template <typename T>
void CPU<T>::END(const int cur_command) {
	allow_command_execution = false;
}

template <typename T>
void CPU<T>::PUSH(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	cpu_stack.push(std::stoi(cpu_commands_vec[cur_command][2]));
}

template <typename T>
void CPU<T>::POP(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	cpu_stack.pop();
}

template <typename T>
void CPU<T>::PUSHR(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	auto iter = cpu_registers.find(cpu_commands_vec[cur_command][2]);
	if (iter == cpu_registers.end()) {
		throw no_such_register(cpu_commands_vec[cur_command][2], cpu_commands_vec[cur_command][0]);
	}
	cpu_stack.push(cpu_registers[cpu_commands_vec[cur_command][2]]);
}

template <typename T>
void CPU<T>::POPR(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	cpu_registers[cpu_commands_vec[cur_command][2]] = cpu_stack.top();
	cpu_stack.pop();
}

template <typename T>
void CPU<T>::ADD(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	T buff = cpu_stack.top();
	cpu_stack.pop();
	T sum = buff + cpu_stack.top();
	cpu_stack.push(buff);
	cpu_stack.push(sum);
}

template <typename T>
void CPU<T>::SUB(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	T buff = cpu_stack.top();
	cpu_stack.pop();
	T sum = buff - cpu_stack.top();
	cpu_stack.push(buff);
	cpu_stack.push(sum);
}

template <typename T>
void CPU<T>::MUL(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	T buff = cpu_stack.top();
	cpu_stack.pop();
	T sum = buff * cpu_stack.top();
	cpu_stack.push(buff);
	cpu_stack.push(sum);
}

template <typename T>
void CPU<T>::DIV(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	T buff = cpu_stack.top();
	cpu_stack.pop();
	T sum = buff / cpu_stack.top();
	cpu_stack.push(buff);
	cpu_stack.push(sum);
}

template <typename T>
void CPU<T>::OUT(const int cur_command) {
	if (!allow_command_execution) {
		return;
	}
	output.push_back(cpu_stack.top());
	cpu_stack.pop();
}

template <typename T>
void CPU<T>::IN(const int cur_command) {
	/* IN PROGRESS */
}

template <typename T>
void CPU<T>::JMP(const int cur_command) {
	execute_commands(tags[cpu_commands_vec[cur_command][2]][0] + 1, tags[cpu_commands_vec[cur_command][2]][1]);
}

template <typename T>
void CPU<T>::RET(const int cur_command) {
	if (cur_tag_building.empty()) {
		throw no_tags_to_do_return(cpu_commands_vec[cur_command][0]);
	}
	// Save endpoint of function
	tags[cur_tag_building][1] = cur_command;
	cur_tag_building.clear();
}

template <typename T>
bool CPU<T>::does_this_command_exist(const int cur_command) {
	const stringvec& line_args = cpu_commands_vec[cur_command];
	// Find by command_name
	auto iter = allowed_commands.find(line_args[1]);
	if (iter == allowed_commands.end()) {
		if (line_args.size() == 2) { // "unknown command without values" = tag
			cur_tag_building = line_args[1]; // save cur tag name
			tags[cur_tag_building] = {cur_command, -1}; // save start position
			return false;
		}
		else {
			throw unknown_command(line_args[1], line_args[0]);
		}
	}
	return true;
}

template <typename T>
void CPU<T>::does_this_command_correct(const int cur_command) {
	const stringvec& line_args = cpu_commands_vec[cur_command];

	auto iter = no_values_commands.find(line_args[1]);
	if ((iter == no_values_commands.end() && line_args.size() == 2) || \
		(iter != no_values_commands.end() && line_args.size() != 2)) {
		throw incorrect_args_value_in_command(line_args[1], line_args[0]);
	}
}

template <typename T>
void CPU<T>::execute_commands(const int start_line, const int end_line) {
	for (int i = start_line; i < end_line; ++i) {
		if (does_this_command_exist(i)) {
			does_this_command_correct(i);
			allowed_commands[cpu_commands_vec[i][1]](i);
		}
	}
}


/* PUBLIC METHODS */


template <typename T>
void CPU<T>::cpu_starter(const std::vector<stringvec>& commands_vec, storage::Stack<T>& stack) {
	cpu_commands_vec = commands_vec;
	cpu_stack = stack;
	execute_commands(0, commands_vec.size());
}

template <typename T>
std::vector<T> CPU<T>::get_output() {
	return output;
}

}