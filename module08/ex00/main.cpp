#include "easyfind.hpp"

int main(){
	
	std::vector<int> vec;
	std::string numStr;
	std::string toFindStr;
	int toFind;
	int num;
	size_t i = 0;
	
	std::cout << "Let's fill in the array (vector) of 10 (!)elements: ";
	while(i < 10){
		std::cout << "Write a number: ";
		std::cin >> numStr;
		num = std::atoi(numStr.c_str());
		numStr.clear();
		vec.push_back(num);
		i++;
	}
	
	std::cout << std::endl;
	std::cout << "Our array(vector, A.K.A. dynamic array)";
	for (i = 0; i < vec.size(); i++){
		std::cout << vec.at(i) << (i == 9 ? ":\n" : ". ");
	}

	std::cout << std::endl;
	std::cout << "WHAT NUMBER DO YOU WANT TO FIND???\n";
	std::cin >> toFindStr;
	toFind = std::atoi(toFindStr.c_str());
	
	(easyfind(vec,toFind));
	return (0);
}