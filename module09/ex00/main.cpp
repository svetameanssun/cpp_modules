#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc == 1){
		std::cerr << "Error: could not open file.\n";
		return (666);
	}
	if (argc > 2){
		std::cerr << "Error: too many args.\n";
		return (666);
	}
	BitcoinExchange btc("data.csv");
	btc.run(argv[1]);
	return (0);
}
