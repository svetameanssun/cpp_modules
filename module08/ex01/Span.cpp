#include "Span.hpp"

Span::Span(){

}

Span::Span(unsigned int number){
}

Span::Span(const Span &other) :N(other.N){
	*this = other;
}

Span &Span::operator=(const Span &other){
	if (this !=&other){
		this->N = other.N;
	}
	return(*this);
}

Span::~Span(){
	
}