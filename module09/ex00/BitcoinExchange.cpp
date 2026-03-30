#include "BitcoinExchange.hpp"
//.csv data example:
// 2010-01-27,0
// 2015-05-11,239.11

BitcoinExchange::BitcoinExchange(const char *csvFile){
	csvToMap(csvFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){ 
	//this->valuesMap = other.valuesMap;:
	//chatgpt version:
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange&other):{
	if (this != &other){
		this->valuesMap = other.valuesMap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}


void BitcoinExchange::run(const char *str){
	processInputFile(str);
}

void BitcoinExchange::calculateAndPrint(float value, float rate, const std::string &date){
	std::cout << date << " => " << rate << "(rate) x " << value << "(value) = " << rate * value << std::endl;
}

bool BitcoinExchange::isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) 
        || (year % 400 == 0);
}

void BitcoinExchange::checkDate(const std::string &date){
	if (date.at(4) != '-' || date.at(7) != '-'){
		throw BitcoinException("wrong date format.\n");
		//std::cout << "Error: wrong date format.\n";
		//return (false);
	}
	// date.substr(from_which_ind, how_many)
	// 2012-01-11 | 1	
	std::string yearStr = date.substr(0,4);
	std::string monthStr = date.substr(5,2);
	std::string dayStr = date.substr(8,2);
	std::stringstream year(yearStr);
	std::stringstream month(monthStr);
	std::stringstream day(dayStr);

	int yearNbr; 
	year >> yearNbr;
	int monthNbr;
	month >> monthNbr;
	int dayNbr; 
	day >> dayNbr;
	if (yearNbr == 0|| monthNbr == 0 || dayNbr == 0){
		throw BitcoinException("wrong date format.\n");
		//std::cout << "Error: wrong date format.\n";
		//return (false);
	}

	if (monthNbr > 12|| monthNbr < 1 || dayNbr < 1 || dayNbr > 31){
		throw BitcoinException("wrong date format.\n");
		//std::cout << "Error: wrong date format.\n";
		//return (false);
	}
	if (monthNbr == 4 || monthNbr == 6
		|| monthNbr == 9 || monthNbr == 11){
		if(dayNbr > 30){
			throw BitcoinExcepion("wrong date format.\n");
			//std::cout << "Error: wrong date format.\n";
			//return (false);	
		}
	}
	else{
		if (isLeapYear(yearNbr)){
			if (monthNbr == 2 && dayNbr > 29){
				throw BitcoinException("wrong date format.\n");
				//std::cout << "Error: wrong date format.\n";
				//return (false);
			}
		}
		else{
			if (monthNbr == 2 && dayNbr > 28){
				throw BitcoinException("wrong date format.\n");
				//std::cout << "Error: wrong date format.\n";
				//return (false);
			}
		}
	}
	time_t inputDate;
	time_t now;
	struct tm datetime;
	datetime.tm_year =  yearNbr - 1900; // Number of years since 1900
	datetime.tm_mon = monthNbr - 1; // Number of months since January
	datetime.tm_mday = dayNbr;
	datetime.tm_hour = 0; datetime.tm_min = 0; datetime.tm_sec = 0;
	datetime.tm_isdst = -1;
	inputDate = mktime(&datetime);
	now = time(&now);
	if (difftime(now, inputDate) < 0){
		throw BitcoinException("future date is used");
		//std::cout << "Error: future date is used.\n";
		//return (false);
	}
	return;
}

void BitcoinExchange::isValidLineFormat(const std::string &line){

	double number;
	if (!checkDate(line.substr(0, 10))){
		throw BitcoinException("wrong date format");
		//return (false);
	}
	/// CHECK THE DATE !!!!!!!!!!!!!!1
	if (line.length() < 14){
		throw BitcoinException("wrong date format\n");
		//std::cout << "Error: wrong date format.\n";
		//return (false);
	}
	if (line.at(11) != '|'){
		throw BitcoinException("bad input => " + line);
		//std::cout << "Error: bad input => " << line << std::endl;
		//return (false);
	}
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
    {
		throw BitcoinException("bad input => " + line);

        //std::cout << "Error: bad input => " << line << std::endl;
        //eturn (false);
    }
	std::string numberStr = line.substr(pos + 3);
	std::stringstream ss(numberStr);
	ss >> number;
	if (ss.fail()){
		throw BitcoinException("bad input => " + line);

		//std::cout << "Error: bad input => " << line << std::endl;
		//return (false);
	}
	std::string remainder;
    if (ss >> remainder) {
		throw BitcoinException("bad input => " + line);

        //std::cout << "Error: bad input => " << numberStr << std::endl;
        //return false;
    }
	if (number < 0.0){
		throw BitcoinException("not a positive number");
		//std::cout << "Error: not a positive number." << std::endl;
		//return (false);
	}
	if (number > 1000.0)
	{
		throw BitcoinException("Error: not a positive number");
    	//std::cout << "Error: too large a number." << std::endl;
		//return (false);
	}
	return (true);
}

float BitcoinExchange::findValueByDate(const std::string &date){
	// Finding the lower bound for key 'd'
  std::map<std::string, float>::iterator it = this->valuesMap.lower_bound(date);

  if (it == valuesMap.end() || it->first != date) {
    // Check if the element found is the first one in the container
    if (it == valuesMap.begin()) {
		throw BitcoinException("no earlier date available\n");
        //std::cerr << "Error: no earlier date available\n";
        //return 0;
    }
    --it;
  }
	return (it->second);
}


void BitcoinExchange::csvToMap(const char *csvFile)
{
	std::string csv(csvFile);
	if (csv.length() < 4 || csv.substr(csv.length() - 4) != ".csv")
	{
		throw BitcoinException("wrong CSV file name format");
		//std::cerr << "Error: wrong CSV file name format\n" << std::endl;
		//return;
	}

	std::ifstream file(csvFile);
	if (!file.is_open())
	{
		throw BitcoinException("could not open CSV file");
		//std::cerr << "Error: could not open CSV file\n" << std::endl;
		//return;
	}

	std::string line;
	std::string dateStr;
	std::string valueStr;
	float value;

	// skip header
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		if (!std::getline(ss, dateStr, ','))
			continue;

		if (!std::getline(ss, valueStr))
			continue;

		std::stringstream valueStream(valueStr);
		valueStream >> value;
		this->valuesMap[dateStr] = value;
	}
	file.close();
}

void BitcoinExchange::processInputFile(const char *txtFile){
	std::ifstream file(txtFile);
	std::string line;
	std::string dateStr;
	std::string rateStr;
	float rate;

	if (!file.is_open()){
		throw BitcoinException("could not open input file.\n");
		//std::cerr << "Error: could not open input file\n";
		//return;
	}
	//  skip header
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try{
			if (line.empty()){
				continue;
			}
			if(!isValidLineFormat(line)){
				continue ;
			}
			std::stringstream ss(line);
			std::getline(ss, dateStr, '|');
			dateStr.erase(dateStr.length() - 1, 1); // remove last char
			std::getline(ss, rateStr);
			if (rateStr.at(0))
				rateStr.erase(0, 1); // remove 1st char
			std::stringstream rateStream(rateStr);
			rateStream >> rate;
			calculateAndPrint(findValueByDate(dateStr), rate, dateStr);
		} catch{
			std::cerr << "Error: " << e.what << etd::endl
		}
	}
	file.close();
}










