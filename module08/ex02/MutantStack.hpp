#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
	public:
		MutantStack() : std::stack<T>{};
		MutantStack(const &MutantStack){};
		MutantStack &operator=(const &MutantStack);
		~MutantStack();
		class iterator : std::iterator<T>{

		};
	private:
		void push(const T &value);
		void pop(void);


};
