#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <exception>

template <class T>
class Array {
	public:
		Array();  // constructor creates an emty array;
		Array(unsigned int n);  // Creates an array of n elements initialized by default.
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		
		
		T &operator[](unsigned int index);
		const T operator[](unsigned int &index) const;
		unsigned int size() const;

	private:
		unsigned int _arraySize;
		T * _array;

};

#include "Array.tpp"

#endif