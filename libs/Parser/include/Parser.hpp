
#include <fstream>
#include "../../CPU/src/CPU.cpp"
#include <vector>
#include <array>


typedef std::vector<std::vector<std::string>> multivec_strings;


/* ERRORS */


struct file_opening_error {
	const char* file_name;
};

struct unexpected_symbol {
	const char sym;
	const int line;
};

struct missing_line_arguments {
	const int line;
};

struct too_many_line_separators_for_2_arguments_received {
	const int line;
};


namespace input {


class Parser {
	private:
		char to_low_register(const char);
		bool is_naming_allowed(const char);
		char skip_emptiness(std::ifstream&, const int);
		bool parse_line(std::ifstream&, const int, multivec_strings&);
	public:
		multivec_strings parse_file(const char*);		
};


}