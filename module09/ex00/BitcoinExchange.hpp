#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <ctime>

class BitcoinExchange{
	public:
		BitcoinExchange(std::string &csvFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange&other);
		~BitcoinExchange();
		
		void processInputFile(const std::string &txtFile);
		void csvToMap(const std::string &csvFile);
		
	private:
		BitcoinExchange();
		std::map<struct tm, float> ratesMap; //stores data.csv
};
