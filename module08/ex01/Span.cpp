/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:40:22 by stitovsk          #+#    #+#             */
/*   Updated: 2026/02/13 19:13:51 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span():N(10), _set(){}

Span::Span(unsigned int number): N(number), _set(){}

Span::Span(const Span &other) :N(other.N), _set(other._set) {}

Span &Span::operator=(const Span &other){
	if (this !=&other){
		this->N = other.N;
		this->_set =other._set;
	}
	return(*this);
}

Span::~Span(){}

void Span::addNumber(int number){
	
	try {
		checkLimit(_set.size(), N);
		_set.insert(number);
	}
	catch(OutOfRangeException &e){
		std::cout << "Exception caught: " << e.what()
		<< " Max " << e.getValue() << " elements"<< std::endl;
	}
}

int Span::shortestSpan(){

	try {
		checkElementNum(_set.size());
		return (*_set.lower_bound(*_set.begin()) - *_set.begin());
	}
	catch(NotEnoughElementsException &e){
		std::cout << "Exception caught: " << e.what()
		<< " Set size = " << e.getValue() << std::endl;
	}
	
}

int Span::longestSpan(){

	try {
		checkElementNum(_set.size());
		return (*this->_set.end() - *this->_set.begin());
	}
	catch(NotEnoughElemsException &e){
		std::cout << "Exception caught: " << e.what()
		<< " Set size = " << e.getValue() << std::endl;
	}
	
}

void Span::fillInArray(std::set <int>::iterator begin, std::set <int>::iterator end){

}