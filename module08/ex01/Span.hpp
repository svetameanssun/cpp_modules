#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
//#include <>


class Span{
	public:
		Span(): N(10){};
		Span(unsigned int number):N(number){};
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillInArray();
	

	private:
		unsigned int N;
		std::set<int> set;

		
};



#endif