#include "Span.hpp"

// My test function to test the Span with a big range of numbers

int	main() {
	try {
	Span sp = Span(10000);												// Create an instance of Span with a max size of 10000

	std::set<int> numbers;											// Create a vector of numbers
	for (int i = 0; i < 10000; i++)										// Loop through 10000 numbers
		numbers.insert(i);											// Add the number to the vector
	
	sp.fillInSet(numbers.begin(), numbers.end());						// Add the range of numbers to the list
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;	// Print the shortest span
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;		// Print the longest span
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}

/*void Span::addRandNumbers(unsigned int amount) {				
	srand(time(NULL));									
	try {												
		for (size_t i = 0; i < amount; i++)			
			this->addNumber(rand());					
	} 	catch (std::exception &e) {						
		std::cerr << e.what() << std::endl;
	}	
}*/