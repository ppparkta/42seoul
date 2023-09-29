#include "Span.hpp"

const char* Span::FullSpanException::what() const throw(){
	return "Span is full!";
}

const char* Span::NoMatchingException::what() const throw(){
	return "No matching elements!";
}

Span::Span():_n(0){

}

Span::Span(unsigned int n):_n(n){

}



Span& Span::operator=(const Span &span){

}

Span::~Span(){

}

void Span::addNumber(unsigned int n){

}

unsigned int Span::shortestSpan(){

}

unsigned int Span::longestSpan(){

}

void Span::addManyNumber(){

}