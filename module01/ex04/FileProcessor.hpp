#ifndef FILE_PROCESSOR_HPP
#define FILE_PROCESSOR_HPP

#include <fstream>  // Для std::ifstream и std::ofstream
#include <string>

bool validateArguments(int argc, char** argv);
std::string generateOutputFileName(const std::string& inputFileName);
bool checkInOutFiles(std::ifstream& inputFile, std::ofstream& outputFile);

#endif