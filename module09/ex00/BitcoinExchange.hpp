#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <cfloat>
#include <stdexcept>

class BitcoinException : public std::runtime_error{
	public:
		BitcoinException(const std::string &message) : std::runtime_error(message){}
};

class BitcoinExchange{
	public:
		BitcoinExchange(const char *csvFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange&other);
		~BitcoinExchange();

		void run(const char *str);
		
		
	private:
		BitcoinExchange();
		std::map<std::string, float> valuesMap; //stores data.csv
		void processInputFile(const char *txtFile);
		void csvToMap(const char *csvFile);
		void isValidLineFormat(const std::string &line);// it used to return bool
		float findValueByDate(const std::string &date);
		void calculateAndPrint(float value, float rate, const std::string &date);
		void checkDate(const std::string &date); // it used to return bool
		bool isLeapYear(int year);
};



#endif

