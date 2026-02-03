#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>



#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
bool easyfind(T &vec, int num){
	if (std::find(vec.begin(), vec.end(), num) == vec.end()){
		std::cout << "The number is nowhere to be found!\n";
		return (false);
	}
	std::cout << "we found the number!\n";
	return (true);
	
}

#endif