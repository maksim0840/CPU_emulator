#pragma once
#include <fstream>
#include <vector>
#include <string>

typedef std::vector<std::vector<std::string>> multivec_strings;

struct file_opening_error {
	const std::string& file_name;
};

namespace input {


class Parser {
	private:
		char to_low_register(const char);
		bool parse_line(std::ifstream&, const int, multivec_strings&);
	public:
		multivec_strings parse_file(const std::string&);		
};


}