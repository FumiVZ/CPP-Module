#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN()
{
    while (!numbers.empty())
        numbers.pop();
}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        expression = other.expression;
        numbers = other.numbers;
    }
    return *this;
}

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::doOperation(int a, int b, char op)
{
    if (op == '+')
    {
        if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
            (b < 0 && a < std::numeric_limits<int>::min() - b))
            throw std::overflow_error("Error: Addition overflow");
        return a + b;
    }
    if (op == '-')
    {
        if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
            (b > 0 && a < std::numeric_limits<int>::min() + b))
            throw std::overflow_error("Error: Subtraction overflow");
        return a - b;
    }
    if (op == '*')
    {
        if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b)
            throw std::overflow_error("Error: Multiplication overflow");
        if (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a)
            throw std::overflow_error("Error: Multiplication overflow");
        if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b)
            throw std::overflow_error("Error: Multiplication overflow");
        if (a < 0 && b < 0 && a < std::numeric_limits<int>::max() / b)
            throw std::overflow_error("Error: Multiplication overflow");
        return a * b;
    }
    if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error: Division by zero");
        if (a == std::numeric_limits<int>::min() && b == -1)
            throw std::overflow_error("Error: Division overflow");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

void RPN::parseToken(const std::string &token)
{
    int number;
    if (token.length() == 1 && isOperator(token[0]))
    {
        if (numbers.size() < 2)
            throw std::runtime_error("Error: Not enough operands");
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        int result = doOperation(a, b, token[0]);
        numbers.push(result);
    }
    else if (token.length() == 1 && std::isdigit(token[0]))
    {
        number = token[0] - '0';
        numbers.push(number);
    }
    else
    {
        throw std::runtime_error("Error");
    }
}

RPN::RPN(const std::string &expr)
{
    expression = expr;
}

void RPN::calculate()
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        parseToken(token);
    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    std::cout << numbers.top() << std::endl;
}
