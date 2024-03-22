#include "../include/CPU.hpp"

namespace proc {

/* CpuOutput */

// protected:


template <typename T>
void CpuOutput<T>::push_output(const T& value) {
	output.push_back(value);
}

template <typename T>
std::vector<T> CpuOutput<T>::get_output() {
	return output;
}


/* CpuRedirect */

// private:

void CpuRedirect::reset() {
	ind_start = -1;
	ind_end = -1;
	break_main_function_flag = false;
}

// protected:

void CpuRedirect::set_redirect(const int start, const int end, const bool break_flag) {
	ind_start = start;
	ind_end = end;
	break_main_function_flag = break_flag;
}

bool CpuRedirect::get_redirect(int& start, int& end) {
	start = ind_start;
	end = ind_end;
	bool break_flag =  break_main_function_flag;
	reset();
	return break_flag;
}


/* CpuRegisters */

// protected:

template <typename T>
void CpuRegisters<T>::set_register(const std::string& name, const T& value, const int line) {
	auto iter = allowed_registers.find(name);
	if (iter == allowed_registers.end()) {
		throw no_such_register(name, line);
	}
	registers[name] = value;
}

template <typename T>
T CpuRegisters<T>::get_register(const std::string& name, const int line) {
	auto iter = registers.find(name);
	if (iter == registers.end()) {
		throw no_such_register(name, line);
	}
	return registers[name];
}


/* CpuCommandsExecuter */

//private:

template <typename T>
T CpuCommandsExecuter<T>::to_num_value(const std::string& value) {
	return std::stoi(value);
}

//protected:

template <typename T>
void CpuCommandsExecuter<T>::BEGIN(const int ind) {
	commands_execute_flag = true;
}

template <typename T>
void CpuCommandsExecuter<T>::END(const int ind) {
	commands_execute_flag = false;
}

template <typename T>
void CpuCommandsExecuter<T>::PUSH(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	Cpu<T>::stack.push(to_num_value(Cpu<T>::commands[ind].value));
}

template <typename T>
void CpuCommandsExecuter<T>::POP(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::PUSHR(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T reg_val = CpuRegisters<T>::get_register(Cpu<T>::commands[ind].value, ind);
	Cpu<T>::stack.push(reg_val);
}

template <typename T>
void CpuCommandsExecuter<T>::POPR(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	CpuRegisters<T>::set_register(Cpu<T>::commands[ind].value, Cpu<T>::stack.top(), ind);
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::ADD(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T buff = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	T add = buff + Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	Cpu<T>::stack.push(add);
}

template <typename T>
void CpuCommandsExecuter<T>::SUB(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T buff = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	T sub = buff - Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	Cpu<T>::stack.push(sub);
}

template <typename T>
void CpuCommandsExecuter<T>::MUL(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T buff = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	T mul = buff * Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	Cpu<T>::stack.push(mul);


}

template <typename T>
void CpuCommandsExecuter<T>::DIV(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T buff = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	T div = buff / Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	Cpu<T>::stack.push(div);

}

template <typename T>
void CpuCommandsExecuter<T>::OUT(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	CpuOutput<T>::push_output(Cpu<T>::stack.top());
	Cpu<T>::stack.pop();
}

// template <typename T>
// void CpuOutput::IN(const int ind) {
// 	if (!commands_execute_flag) {
// 		return;
// 	}
// }

template <typename T>
void CpuCommandsExecuter<T>::JMP(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	std::string name = Cpu<T>::commands[ind].value;
	CpuRedirect::set_redirect(Cpu<T>::redirects[name].start_ind, Cpu<T>::commands.size(), true);

}

template <typename T>
void CpuCommandsExecuter<T>::JEQ(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 == Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::JNE(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 != Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::JA(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 > Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::JAE(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 >= Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::JB(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 < Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::JBE(const int ind) {
	if (!commands_execute_flag) {
		return;
	}
	T value1 = Cpu<T>::stack.top();
	Cpu<T>::stack.pop();
	if (value1 <= Cpu<T>::stack.top()) {
		Cpu<T>::stack.pop();
		JMP(ind);
		return;
	}
	Cpu<T>::stack.pop();
}

template <typename T>
void CpuCommandsExecuter<T>::CALL(const int ind) {
	std::string name = Cpu<T>::commands[ind].value + ':';
	//std::cout << "---" << Cpu<T>::commands[ind].value << ' ' << Cpu<T>::redirects[name].start_ind << ' ' << Cpu<T>::redirects[name].ret_ind << "---";
	CpuRedirect::set_redirect(Cpu<T>::redirects[name].start_ind, Cpu<T>::redirects[name].ret_ind, false);

}


/* CpuCommandsReader */

// private

// new loop (function jump/call found)
template <typename T>
bool CpuCommandsReader<T>::check_for_redirects() { // returns 1 if jmp, returns 0 if call
	int start = -1;
	int end = -1;
	bool break_flag = CpuRedirect::get_redirect(start, end);
	if (start != -1) {
		read(start + 1, end);
	}
	return break_flag;
}

// protected:

template <typename T>
void CpuCommandsReader<T>::read(const int start_ind, const int end_ind) {
	for (int ind = start_ind; ind < end_ind; ++ind) {
		if (check_for_redirects()) {
			return; // end
		}
		command_functions[Cpu<T>::commands[ind].type](ind);
	}
}


/* CpuStarter */

// public:

template <typename T>
void CpuStarter<T>::start(const commands_vec& commands_preprocessor, 
	const redirects_map& redirects_preprocessor, storage::Stack<T>& recieved_stack) {

	Cpu<T>::stack = recieved_stack;
	Cpu<T>::commands = commands_preprocessor;
	Cpu<T>::redirects = redirects_preprocessor;
	CpuCommandsReader<T>::read(0, commands_preprocessor.size());
}

template <typename T>
std::vector<T> CpuStarter<T>::get_result() {
	return CpuOutput<T>::get_output();
}


}