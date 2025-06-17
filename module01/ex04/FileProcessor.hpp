#ifndef FILE_PROCESSOR_HPP
#define FILE_PROCESSOR_HPP

#include <string>
#include <fstream> // Для std::ifstream и std::ofstream

bool validateArguments(int argc, char** argv);
std::string generateOutputFileName(const std::string& inputFileName);
bool checkInOutFiles(std::ifstream& inputFile, std::ofstream& outputFile);
std::string replaceAllOccurrences(std::string line, const std::string& s1, const std::string& s2);


#endif