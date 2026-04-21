#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

#endif


//Old Version:
// It is better use the version above, because of:
// 1) Practice of returning an iterator
// 2) Working with const/non-const containers
// 3) Wroking with const/non-const iterators.
// 4) Exceptions
/*
	
	template <typename T>
	bool easyfind(T &vec, int num){
		if (std::find(vec.begin(), vec.end(), num) == vec.end()){
			std::cout << "The number is nowhere to be found!\n";
			return (false);
		}
		std::cout << "we found the number!\n";
		return (true);
		
	}*/