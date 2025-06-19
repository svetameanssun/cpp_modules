/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:09:20 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 13:26:14 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {

    if(validateArguments(argc, argv) == false)
        return (1);

    std::string inputFileName = argv[1];
    std::string outputFileName =  generateOutputFileName(inputFileName);
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::cout << inputFileName << "\n"
              << outputFileName << "\n"
              << s1 << "\n"
              << s2 << "\n";

    if(s1.empty()) {
        std::cerr << "Error: String to find (s1) cannot be empty.\n";
        return (1);
    }

    std::ifstream inputFile(inputFileName.c_str());
    std::ofstream outputFile(outputFileName.c_str());
    if(checkInOutFiles(inputFile, outputFile) == false) {
        return (1);
    }

    std::string line;
    while(std::getline(inputFile, line)) {
        size_t currentPos = 0;
        while((currentPos = line.find(s1, currentPos)) != std::string::npos) {
            line.erase(currentPos, s1.length());
            line.insert(currentPos, s2);
            currentPos += s2.length();
        }
        outputFile << line << '\n';
    }
    inputFile.close();
    outputFile.close();

    return (0);
}