#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	try{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		easyfind(vec, 42);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}