#include <iostream>
#include <stack>
#include <list>
#include <cstdlib>

template <typename T>
class MutantStack: public std::stack<T>{
	public:
		MutantStack() : std::stack<T>{};
		MutantStack(const &MutantStack){};
		MutantStack &operator=(const &MutantStack);
		~MutantStack();
		iterator begin();
		iterator end();

	private:
		typedef typename std::stack<T>::container_type::iterator iterator;



};
