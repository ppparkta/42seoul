#pragma once
#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &stack){
	*this = stack;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &stack){
	std::stack<T>::operator=(stack);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, MutantStack<T> &stack)
{
	return os<<stack.top();
}

#endif