#include "FileProcessor.hpp"
#include <iostream> 

bool validateArguments(int argc, char** argv){
    if (argc != 4){
        std::cerr << "Error: Wrong number of arguments.\n";
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_find> <string_to_replace>\n";
        return (false);
    }
    return (true);
}


std::string generateOutputFileName(const std::string& inputFileName){
    std::string outputFileName = inputFileName;
    outputFileName += ".replace";
    return (outputFileName);
}

bool checkInOutFiles(std::ifstream& inputFile, std::ofstream& outputFile){
    if (!inputFile.is_open()){
        std::cerr << "Error: Could not open input file." <<"\n";
        return (false);
    }
    if (!outputFile.is_open()){
        std::cerr << "Error: Could not create/open output file." <<"\n";
        inputFile.close();
        return (false);
    }
    return (true);
}

