#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "../../Stack/src/Stack.cpp"
#include "../../Stack/include/Stack.hpp"


typedef const std::string& str;


class Commands {

private:
	void BEGIN(str command, str value) {
		command_execution = true;
		std::cout << command << ' ' << value;
	}

	void END(str command, str value) {
		command_execution = true;
	}

	void PUSHR(str command, const str value) {

	}

	void POPR(str command, const str value) {

	}

	void ADD(str command, str value) {

	}

	void SUB(str command, str value) {

	}

	void MUL(str command, str value) {

	}

	void DIV(str command, str value) {

	}

	void OUT(str command, str value) {

	}

	void IN(str command, str value) {

	}

public:
	bool command_execution = false;

	void command_define(str command, str value) {
		std::unordered_map<std::string, std::function<void(str, str)>> allowed_commands = {
			{"begin", [this](str command, str value) {this->BEGIN(command, value);}},
			{"end", [this](str command, str value) {this->END(command, value);}},
			{"pushr", [this](str command, str value) {this->PUSHR(command, value);}},
			{"popr", [this](str command, str value) {this->POPR(command, value);}},
			{"add", [this](str command, str value) {this->ADD(command, value);}},
			{"sub", [this](str command, str value) {this->SUB(command, value);}},
			{"mul", [this](str command, str value) {this->MUL(command, value);}},
			{"div", [this](str command, str value) {this->DIV(command, value);}},
			{"out", [this](str command, str value) {this->OUT(command, value);}},
			{"in", [this](str command, str value) {this->IN(command, value);}},
		};
		
		auto iter = allowed_commands.find(command);
		if (iter == allowed_commands.end()) {
			throw "unknown command";
		}

		allowed_commands[command](command, value);

	}

};


int main() {
	Commands b;
	b.command_define("begin", "1d5");
	
	return 0;
}