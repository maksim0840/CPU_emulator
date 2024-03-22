#include "../../Stack/src/Stack.cpp"
#include "../../Preprocessor/src/Preprocessor.cpp"
#include <unordered_set>


namespace proc {


struct no_such_register {
	std::string name;
	int line;
};

typedef preproc::Preprocessor::commands_vec commands_vec;
typedef preproc::Preprocessor::redirects_map redirects_map;


template <typename T>
class Cpu {
	protected:
		storage::Stack<T> stack;
		commands_vec commands;
		redirects_map redirects;
};


template <typename T>
class CpuOutput {
	private:
		std::vector<T> output;

	protected:
		void push_output(const T&);
		std::vector<T> get_output();
};


class CpuRedirect {
	private:
		int ind_start = -1;
		int ind_end = -1;	
		bool break_main_function_flag = false;

		void reset();

	protected:
		void set_redirect(const int, const int, const bool);
		bool get_redirect(int&, int&);
};


template <typename T>
class CpuRegisters {
	private:
		std::unordered_map<std::string, T> registers;
		std::unordered_set<std::string> allowed_registers = {
			"ax", "bx", "cx", "dx",
			"bp", "sp", "si", "di",  
			"ip", "flags", "pc"
		};

	protected:
		void set_register(const std::string&, const T&, const int);
		T get_register(const std::string&, const int);
};


template <typename T>
class CpuCommandsExecuter: protected virtual Cpu<T>, protected virtual CpuRedirect, private virtual CpuOutput<T>, private virtual CpuRegisters<T> {
	private:
		bool commands_execute_flag = false;
		T to_num_value(const std::string&);

	protected:
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
		void IN(const int){};
		void JMP(const int);
		void JEQ(const int);
		void JNE(const int);
		void JA(const int);
		void JAE(const int);
		void JB(const int);
		void JBE(const int);
		void CALL(const int);
		void RET(const int){};
		void REDIRECT(const int){};
};


template <typename T>
class CpuCommandsReader: private virtual CpuCommandsExecuter<T> {
	private:
		std::unordered_map<preproc::Preprocessor::Command, std::function<void(const T)>> command_functions = {
			{preproc::Preprocessor::Command::BEGIN, [this](const int ind) {this->CpuCommandsExecuter<T>::BEGIN(ind);}},
			{preproc::Preprocessor::Command::END, [this](const int ind) {this->CpuCommandsExecuter<T>::END(ind);}},
			{preproc::Preprocessor::Command::PUSH, [this](const int ind) {this->CpuCommandsExecuter<T>::PUSH(ind);}},
			{preproc::Preprocessor::Command::POP, [this](const int ind) {this->CpuCommandsExecuter<T>::POP(ind);}},
			{preproc::Preprocessor::Command::PUSHR, [this](const int ind) {this->CpuCommandsExecuter<T>::PUSHR(ind);}},
			{preproc::Preprocessor::Command::POPR, [this](const int ind) {this->CpuCommandsExecuter<T>::POPR(ind);}},
			{preproc::Preprocessor::Command::ADD, [this](const int ind) {this->CpuCommandsExecuter<T>::ADD(ind);}},
			{preproc::Preprocessor::Command::SUB, [this](const int ind) {this->CpuCommandsExecuter<T>::SUB(ind);}},
			{preproc::Preprocessor::Command::MUL, [this](const int ind) {this->CpuCommandsExecuter<T>::MUL(ind);}},
			{preproc::Preprocessor::Command::DIV, [this](const int ind) {this->CpuCommandsExecuter<T>::DIV(ind);}},
			{preproc::Preprocessor::Command::OUT, [this](const int ind) {this->CpuCommandsExecuter<T>::OUT(ind);}},
			{preproc::Preprocessor::Command::IN, [this](const int ind) {this->CpuCommandsExecuter<T>::IN(ind);}},
			{preproc::Preprocessor::Command::JMP, [this](const int ind) {this->CpuCommandsExecuter<T>::JMP(ind);}},
			{preproc::Preprocessor::Command::JEQ, [this](const int ind) {this->CpuCommandsExecuter<T>::JEQ(ind);}},
			{preproc::Preprocessor::Command::JNE, [this](const int ind) {this->CpuCommandsExecuter<T>::JNE(ind);}},
			{preproc::Preprocessor::Command::JA, [this](const int ind) {this->CpuCommandsExecuter<T>::JA(ind);}},
			{preproc::Preprocessor::Command::JAE, [this](const int ind) {this->CpuCommandsExecuter<T>::JAE(ind);}},
			{preproc::Preprocessor::Command::JB, [this](const int ind) {this->CpuCommandsExecuter<T>::JB(ind);}},
			{preproc::Preprocessor::Command::JBE, [this](const int ind) {this->CpuCommandsExecuter<T>::JBE(ind);}},
			{preproc::Preprocessor::Command::CALL, [this](const int ind) {this->CpuCommandsExecuter<T>::CALL(ind);}},
			{preproc::Preprocessor::Command::RET, [this](const int ind) {this->CpuCommandsExecuter<T>::RET(ind);}},
			{preproc::Preprocessor::Command::REDIRECT, [this](const int ind) {this->CpuCommandsExecuter<T>::REDIRECT(ind);}},
		};

		bool check_for_redirects();

	protected:
		void read(const int, const int);
};


template <typename T>
class CpuStarter: private virtual Cpu<T>, private virtual CpuCommandsReader<T>, private virtual CpuOutput<T> {
	public:
		void start(const commands_vec&, const redirects_map&, storage::Stack<T>&);		
		std::vector<T> get_result();
};


}