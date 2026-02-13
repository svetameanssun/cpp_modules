#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <exception>



class Span{
	public:
		Span(unsigned int number);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillInArray(std::set <int>::iterator begin, std::set <int>::iterator end);

		class NotEnoughElementsException : public std::exception{
			public:
				const char *what() const throw();
		};

		class OutOfRangeException :public std::exception{
			const char * what() const throw();
		};
	

	private:
		unsigned int N;// s[0...N-1]
		std::set<int> _set;
		Span();	
};




#endif