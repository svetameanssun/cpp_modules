/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:40:22 by stitovsk          #+#    #+#             */
/*   Updated: 2026/03/31 17:39:53 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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


const std::set <int> Span::getSet(){
	return (this->_set);
}

void Span::printSet(){
	std::set <int> aux = getSet();
	std::set <int>::iterator it = aux.begin();
	std::cout << "My set --------------\n";
	for(;  it != aux.end(); it++){
		std::cout << *it << "\n";
	}
	std::cout << "----------------\n";
}

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
	std::set<int>::iterator it = _set.begin();
	std::set<int>::iterator next = it;
	++next;
	int minSpan = *next - *it;

	for (; next != _set.end(); ++it, ++next) {
    	int diff = *next - *it;
		if (diff < minSpan){
			minSpan = diff;
		}
	}
	return (minSpan);
}

int Span::longestSpan(){

	if (_set.empty() || _set.size() == 1){
		throw Span::NotEnoughElementsException();
	}
	std::set <int>::iterator lastElem = _set.end();
	--lastElem;
	return (*lastElem - *this->_set.begin());
}

const char *Span::NotEnoughElementsException::what() const throw() {	
	return "Not enough numbers in the list";			
}

const char *Span::OutOfRangeException::what() const throw() {	
	return "Max size reached";							
}
	


