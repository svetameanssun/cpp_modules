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
		typedef typename std::stack<T>::container_type::iterator iterator;
	private:
		void push(const T &value);
		void pop(void);


};
