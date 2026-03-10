#include "MutantStack.hpp"
#include <list>
#include <iostream>

// My test function to test the MutantStack with a stack and a list

template <typename Container>
void testContainer(Container &container) {
	container.push(5);									// Add the number 5 to the stack
	container.push(17);									// Add the number 17 to the stack
	std::cout << "Top element: " << container.top() << std::endl;	// Print the top of the stack (17)
	container.pop();									// Remove the top of the stack (17)
	std::cout << "Size: " << container.size() << std::endl;			// Print the size of the stack with only 1 element (1)
	container.push(3);									// Add the number 3 to the stack
	container.push(5);									// Add the number 5 to the stack
	container.push(737);								// Add the number 737 to the stack
	container.push(0);									// Add the number 0 to the stack

	typename Container::iterator it = container.begin();	// Create an iterator for the beginning of the stack
	typename Container::iterator ite = container.end();	// Create an iterator for the end of the stack
	++it;												// Move the iterator to the next element
	--it;												// Move the iterator to the previous element
	while (it != ite)									// Loop through the stack while the iterator is not at the end
	{
		std::cout << *it << std::endl;					// Print the element at the iterator
		++it;											// Move the iterator to the next element
	}
}

template <>
void testContainer(std::list<int> &container) {
	container.push_back(5);								// Add the number 5 to the stack 
	container.push_back(17);							// Add the number 17 to the stack
	std::cout << "Top element: " << container.back() << std::endl;	// Print the top of the stack (17)
	container.pop_back();								// Remove the top of the stack (17)
	std::cout << "Size: " << container.size() << std::endl;			// Print the size of the stack with only 1 element (1)
	container.push_back(3);								// Add the number 3 to the stack
	container.push_back(5);								// Add the number 5 to the stack
	container.push_back(737);							// Add the number 737 to the stack
	container.push_back(0);								// Add the number 0 to the stack

	std::list<int>::iterator it = container.begin();	// Create an iterator for the beginning of the stack
	std::list<int>::iterator ite = container.end();		// Create an iterator for the end of the stack
	++it;												// Move the iterator to the next element
	--it;												// Move the iterator to the previous element
	while (it != ite)									// Loop through the stack while the iterator is not at the end
	{
		std::cout << *it << std::endl;					// Print the element at the iterator
		++it;											// Move the iterator to the next element
	}
}

int	main() {
	std::cout << "Testing MutantStack with stack" << std::endl;	// Print the title of the test
	MutantStack<int> mstack;							// Create an instance of MutantStack
	testContainer(mstack);								// Test the stack with the test function

	std::cout << "Testing MutantStack with list"  << std::endl;
	std::list<int> list;								// Create a list of integers to test the MutantStack
	testContainer(list);								// Test the list with the same function

	return 0;
}




/*int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}*/