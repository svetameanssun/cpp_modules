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

 ParserResultPrivmsg::stringToVec(std::string str, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while(getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}


void BitcoinExchange::csvToMap(const std::string &csvFile){
	char delim = ',';
	std::string date;
	std::string rate;
	std::string line;
	
	if (csvFile.find(".csv") == std::sting::npos){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: wrong CSV file name format\n";
		return;
	}
	if (csvFile.find(".csv") != csvFile.length() - 4){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: wrong CSV file name format\n";
	}
	std::ifstream csvFileRead(csvFile); //read from file, because it we read from file, and this way get an input to this stream
	if (!csvFileRead.is_open()){
		//temporal solution, later will be replaced with exception
		std::cerr << "Error: could not open CSV file\n";
	}



	csvFileRead.close();

}
