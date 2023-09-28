#pragma once
#ifndef __EASYFINDE_HPP__
#define __EASYFINDE_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <exception>

class CanNotFindTargetException : public std::exception {
	public:
		virtual const char * what() const throw(){ return "Can not find target!"; }
};

template<typename T>
typename T::iterator easyfind(T &t, const int target)
{
	typename T::iterator cursor;
	cursor = find(t.begin(), t.end(), target);
	if (cursor == t.end())
		throw CanNotFindTargetException();
	else
		return cursor;
}

#endif