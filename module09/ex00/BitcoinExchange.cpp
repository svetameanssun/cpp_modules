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

/*



2012-01-11 | 1				  2012-01-11 => 1 = 7.1

2012-01-11 | -1               Error: not a positive number.
2001-42-42                    Error: bad input => 2001-42-42
2001-10-10 / 1				  Error: bad input => 2001-10-10 / 1
2012-01-11 | 2147483648 	  Error: too large a number.
01-11-2012                    Error: wrong date format.
2012/01/11 | 1				  Error: wrong date format.


*/
void BitcoinExchange::processInputFile(const std::string &txtFile){
	std::istream file(txtFile);
}


bool BitcoinExchange::isValidLineFormat(const std::string &line){

	double number;

	if (line.length() < 14){
		std::cout << "Error: wrong date format.\n";
		return (false);
	}
	if (line.at(4) != '-' || line.at(7) != '-'){
		std::cout << "Error: wrong date format.\n";
		return (false);
	}
	if (line.at(11) != '|'){
		std::cout << "Error: bad input => " << line;
		return (false);
	}
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return (false);
    }
	std::string numberStr = line.substr(pos + 3);
	std::stringstream ss(numberStr);
	ss >> number;
	if (ss.fail()){
		std::cout << "Error: bad input => " << line;
		return (false);
	}
	std::string remainder;
    if (ss >> remainder) {
        std::cout << "Error: bad input => " << numberStr << std::endl;
        return false;
    }
	if (number < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (number > 1000)
	{
    	std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
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
std::ostream &os operator<<(std::ostream &out,BitcoinExchange &btc){
	out << "=> " <<  = 7.1
	return (out);
}