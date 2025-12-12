#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>

class RPN
{
private:
    std::string expression;
    std::stack<int> numbers;

    bool isOperator(char c);
    int doOperation(int a, int b, char op);
    void parseToken(const std::string &token);

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    RPN(const std::string &expr);
    void calculate();
};

#endif