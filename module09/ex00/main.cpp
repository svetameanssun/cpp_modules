
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	//Temporal solution, later -> exception
	try{
		

	if (argc == 1){
		throw BitcoinException("could not open file.");
		//std::cerr << "Error: could not open file.\n";
		//return (1);
	}
	} catch (const std::exception &e){
		std::cerr << "Fatal error: " << e.what() << std::endl;
		retrun (1);
	}
	try{
	if (argc > 2){
		throw BitcoinException("too many args.")
		//std::cerr << "Error: too many args.\n";
		//return (1);
	} catch (const std::exception& e){
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return (1);
	}
	BitcoinExchange btc("data.csv");
	btc.run(argv[1]);
	return (0);
}