#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    //I want to create a shortcut name called iterator for a very long type.
    //alias
    typedef typename std::stack<T>::container_type::iterator iteraty;

    iteraty begin() { return this->c.begin(); }
    iteraty end() { return this->c.end(); }

    typedef typename std::stack<T>::container_type::const_iterator consty_iteraty;
    consty_iteraty begin() const { return this->c.begin(); }
	consty_iteraty end() const { return this->c.end(); }

};






#endif

/*
#include <iostream>
#include <stack>
#include <list>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Canonical form
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	// Iterator types
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterators
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};*/
