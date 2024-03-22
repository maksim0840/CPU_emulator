#include "../../Parser/src/Parser.cpp"
#include "../../CPU/src/CPU.cpp" // Stack and Preprocessor libs connected to CPU lib

namespace run {


struct incorrect_number_of_console_arguments {
	const int input_arguments;
};

template <typename T>
class Starter {
	private:
		std::vector<T> result;
		
	public:
		void execute(int, char* []);
		std::vector<T> get_result();
};


}