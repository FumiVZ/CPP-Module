#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        data = other.data;
    }
    return *this;
}
void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        return;
    }
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, ',') && std::getline(ss, valueStr))
        {
            std::istringstream valueStream(valueStr);
            float value;
            valueStream >> value;
            data[date] = value;
        }
    }
    file.close();
}

void BitcoinExchange::processFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        std::string::size_type pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        date = trim(date);
        valueStr = trim(valueStr);

        float value;

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(valueStr, value))
        {
            if (valueStr.empty() || valueStr.find_first_not_of(" \t\n\r") == std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
            else
            {
                std::istringstream iss(valueStr);
                float testValue;
                iss >> testValue;
                if (!iss.fail() && iss.eof())
                {
                    if (testValue < 0)
                        std::cerr << "Error: not a positive number." << std::endl;
                    else if (testValue > 1000)
                        std::cerr << "Error: too large a number." << std::endl;
                }
                else
                {
                    std::cerr << "Error: bad input => " << line << std::endl;
                }
            }
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate < 0)
        {
            std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();
}

std::string BitcoinExchange::trim(const std::string &str)
{
    std::string::size_type start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";

    std::string::size_type end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (std::string::size_type i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    int year, month, day;
    yearStream >> year;
    monthStream >> month;
    dayStream >> day;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
    if (valueStr.empty())
        return false;

    std::istringstream iss(valueStr);
    iss >> value;

    if (iss.fail() || !iss.eof())
        return false;

    if (value < 0 || value > 1000)
        return false;

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, float>::iterator it = data.lower_bound(date);

    if (it != data.end() && it->first == date)
        return it->second;

    if (it == data.begin())
        return -1;

    --it;
    return it->second;
}