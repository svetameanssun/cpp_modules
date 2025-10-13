#include "iter.hpp"
#include <cstdlib>  // rand, srand
#include <ctime>  // time



template <typename T>
void goodElemets(T element){
	std::cout << element << std::endl;

	// Seed the random number generator with the current time
    std::srand(std::time(NULL));
	int randNumber = std::rand() % 100 + 1;
	if (randNumber % 3 == 0){
		std::cout << "It is an amazing element!\n";
	}
	else if (randNumber % 2 == 0){
		std::cout << "It is the best element in the world!\n";
	}
	else if (randNumber % 7 == 0){
		std::cout << "Wow, I cannot believe such a perfect element exists!\n";
	}
	else{
		std::cout << "Outstanding element!\n";
		
	}
}

template <typename T>
void badElemets(T element){
	std::cout << element << std::endl;
	
	std::srand(std::time(NULL));
	int randNumber = std::rand() %100 + 1;
		if (randNumber % 3 == 0){
		std::cout << "It is a bad element!\n";
	}
	else if (randNumber % 2 == 0){
		std::cout << "It is the worst element in the world!\n";
	}
	else if (randNumber % 7 == 0){
		std::cout << "Wow, I cannot believe such a damb element exists!\n";
	}
	else{
		std::cout << "Horrible element!\n";
		
	}
}

template <typename T>
void normalElemets(T element){
	
	std::cout << element << std::endl;

	std::srand(std::time(NULL));
	int randNumber = std::rand() % 100 + 1;
		if (randNumber % 3 == 0){
		std::cout << "It is just an OK element\n";
	}
	else if (randNumber % 2 == 0){
		std::cout << "Not bad, nor good. Just an okay element\n";
	}
	else if (randNumber % 7 == 0){
		std::cout << "It exists, and it is OK\n";
	}
	else{
		std::cout << "Just a standard element!\n";
		
	}
}

int main(){
	int myIntArr[] = {10, 33, 32322, 4, 55,55};
	double myDoubleArr[] = {12.1, 13.2, 232.4, 333.6};
	float myFloatArr[] = {1277.1, 135.2, 2324.4, 3733.6};
	iter(myIntArr, sizeof(myIntArr) / sizeof(int) , normalElemets);
	iter(myDoubleArr, sizeof(myDoubleArr) / sizeof(double) , badElemets);
	iter(myFloatArr, sizeof(myFloatArr) / sizeof(float) , goodElemets);
}

