#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
    bool isValidDate(const std::string &date);
    bool isValidValue(const std::string &valueStr, float &value);
    float getExchangeRate(const std::string &date);
    std::string trim(const std::string &str);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    void loadData(const std::string &filename);
    void processFile(const std::string &filename);
};

#endif