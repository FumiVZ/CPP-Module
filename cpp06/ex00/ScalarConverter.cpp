#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cerrno>
#include <limits>
#include <cctype>
#include <cmath>

bool isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}

int findPrecision(double d)
{
	std::ostringstream oss;
	oss << d;
	std::string str = oss.str();
	size_t dot = str.find('.');
	if (dot != std::string::npos)
	{
		size_t lastNonZero = str.find_last_not_of('0', str.size() - 1);
		if (lastNonZero == dot)
		{
			return 0;
		}
		else if (lastNonZero != std::string::npos)
		{
			return lastNonZero - dot;
		}
		return str.size() - dot - 1;
	}
	return 0;
}

void printChar(double d, const std::string &literal)
{
	std::cout << "char: ";
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		if (isDisplayable(literal[0]))
		{
			std::cout << "'" << literal[0] << "'" << std::endl;
		}
		else
		{
			std::cout << "Non displayable" << std::endl;
		}
		return;
	}
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(d);
	if (!isDisplayable(c))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "'" << c << "'" << std::endl;
	}
}

void printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(d) << std::endl;
	}
}

void printFloat(double d)
{
	std::cout << "float: ";
	if (std::isnan(d))
	{
		std::cout << "nanf" << std::endl;
		return;
	}
	if (std::isinf(d))
	{
		std::cout << (d < 0 ? "-inff" : "inff") << std::endl;
		return;
	}
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	float f = static_cast<float>(d);
	std::ostringstream oss;
	oss << std::setprecision(7) << f;
	std::string result = oss.str();
	size_t pos = result.find('.');
	if (pos != std::string::npos)
	{
		size_t lastNonZero = result.find_last_not_of('0');
		if (lastNonZero != std::string::npos)
		{
			if (result[lastNonZero] == '.')
				lastNonZero--;
			result.erase(lastNonZero + 1);
		}
	}
	if (result.find('.') == std::string::npos)
		result += ".0";
	std::cout << result << "f" << std::endl;
}

void printDouble(double d)
{
	std::cout << "double: ";
	if (std::isnan(d))
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (std::isinf(d))
	{
		std::cout << (d < 0 ? "-inf" : "inf") << std::endl;
		return;
	}
	std::ostringstream oss;
	oss << std::setprecision(15) << d;
	std::string result = oss.str();
	size_t pos = result.find('.');
	if (pos != std::string::npos)
	{
		size_t lastNonZero = result.find_last_not_of('0');
		if (lastNonZero != std::string::npos)
		{
			if (result[lastNonZero] == '.')
				lastNonZero--;
			result.erase(lastNonZero + 1);
		}
	}
	if (result.find('.') == std::string::npos)
		result += ".0";
	std::cout << result << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: empty input" << std::endl;
		return;
	}
	char *endPtr;
	const char *str = literal.c_str();
	double d = std::strtod(str, &endPtr);
	bool isChar = (literal.length() == 1 && !isdigit(literal[0]));
	bool validConversion = (endPtr == str + literal.length()) ||
						   (literal.find('f') == literal.length() - 1 && endPtr == str + literal.length() - 1);
	if (!isChar && (errno == ERANGE || !validConversion))
	{
		std::cerr << "Error: invalid input" << std::endl;
		return;
	}
	if (isChar)
	{
		d = static_cast<double>(literal[0]);
	}
	printChar(d, literal);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
