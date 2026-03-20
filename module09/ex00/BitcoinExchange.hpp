#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <cfloat>

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
		bool isValidLineFormat(const std::string &line);
		float findValueByDate(const std::string &date);
		void calculateAndPrint(float value, float rate, const std::string &date);
		bool checkDate(const std::string &date);
		bool isLeapYear(int year);
};

