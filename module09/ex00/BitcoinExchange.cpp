#include "BitcoinExchange.hpp"
//.csv data example:
// 2010-01-27,0
// 2015-05-11,239.11

BitcoinExchange::BitcoinExchange(std::string &csvFile){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	this->ratesMap =other.ratesMap;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange&other){
	if (this != &other){
		this->ratesMap = other.ratesMap;
	}
	return (*this);
}


BitcoinExchange::~BitcoinExchange(){

}
		
void BitcoinExchange::processInputFile(const std::string &txtFile){

}



void BitcoinExchange::csvToMap(const std::string &csvFile)
{
	if (csvFile.length() < 4 || csvFile.substr(csvFile.length() - 4) != ".csv")
	{
		std::cerr << "Error: wrong CSV file name format\n";
		return;
	}

	std::ifstream file(csvFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open CSV file\n";
		return;
	}

	std::string line;
	std::string date;
	std::string rateStr;
	float rate;

	// skip header
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		if (!std::getline(ss, date, ','))
			continue;

		if (!std::getline(ss, rateStr))
			continue;

		std::stringstream rateStream(rateStr);
		rateStream >> rate;
		this->ratesMap[date] = rate;
	}

	file.close();
}
