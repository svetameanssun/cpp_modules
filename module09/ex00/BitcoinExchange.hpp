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
		BitcoinExchange(std::string &csvFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange&other);
		~BitcoinExchange();
		
		void processInputFile(const std::string &txtFile);
		void csvToMap(const std::string &csvFile);
		bool isValidLineFormat(const std::string &line);

		
	private:
		BitcoinExchange();
		std::map<std::string, float> ratesMap; //stores data.csv
};

std::ostream &os operator<<(std::ostream &out,BitcoinExchange &btc);
