#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cerrno>
#include <limits>
#include <cctype>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &);

public:
	static void convert(const std::string &literal);
};

#endif