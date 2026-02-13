/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:40:22 by stitovsk          #+#    #+#             */
/*   Updated: 2026/02/13 20:43:45 by stitovsk         ###   ########.fr       */
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
	
	if(this->_set.size() == this->N){
		throw Span::OutOfRangeException();
	}
	this->_set.insert(number);
}

void Span::fillInSet(std::set <int>::iterator begin, std::set <int>::iterator end){
	if (this->_set.size() + std::distance(begin,end) > this->N){
		throw Span::OutOfRangeException();
	}
	this->_set.insert(begin, end);
	
}


int Span::shortestSpan(){

	if (_set.empty() || _set.size() == 1){
		throw Span::NotEnoughElementsException();
	}
		
	return (*_set.lower_bound(*_set.begin()) - *_set.begin());
}

int Span::longestSpan(){

	if (_set.empty() || _set.size() == 1){
		throw Span::NotEnoughElementsException();
	}
		return (*this->_set.end() - *this->_set.begin());
}

