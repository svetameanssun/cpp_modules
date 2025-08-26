#include "../include/LiteralDetector.hpp"
#include "../include/ScalarConverter.hpp"
#include "../include/ExceptWrongInp.hpp"

int main(int argc, char**argv){
	if (argc !=2){
		std::cerr << "Error: Wrong Number of Args"; 
		return 1;
	}
	try{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}