#include "BitcoinExchange.hpp"

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



void BitcoinExchange::csvToMap(const std::string &csvFile){
	char delim = ',';
	std::string line;
	std::string item;
	std::string after;
	size_t pos;
	float rate;

	if (csvFile.find(".csv") == std::string::npos){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: wrong CSV file name format\n";
		return;
	}
	if (csvFile.find(".csv") != csvFile.length() - 4){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: wrong CSV file name format\n";
	}
	std::ifstream file(csvFile); //read from file, because it we read from file, and this way get an input to this stream
	if (!file.is_open()){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: could not open CSV file\n";
	}
	while(std::getline(file,line)){
		std::stringstream ss(line);
		while(getline(ss, item, delim)){
			pos = line.find(',');
			after  = line.substr(pos + 1);
			std::stringstream floatss(after);
			floatss >> rate;
			this->ratesMap[item] = rate;
		}
	}
	file.close();

}
