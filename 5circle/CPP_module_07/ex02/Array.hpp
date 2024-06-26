#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _size;

public:
	Array() : _arr(new T(0)), _size(0) {}
	Array(unsigned int n) : _arr(new T[n]), _size(n) {}
	Array(const Array &array)
	{
		this->_size = array.size();
		this->_arr = new T[array.size()];
		for (unsigned int i = 0; i < array.size(); i++)
			this->_arr[i] = array[i];
	}
	Array &operator=(const Array &array)
	{
		if (this->_arr != NULL)
			delete[] this->_arr;
		this->_size = array.size();
		this->_arr = new T[array.size()];
		for (unsigned int i = 0; i < array.size(); i++)
			this->_arr[i] = array[i];
		return *this;
	}
	~Array()
	{
		delete[] this->_arr;
	}
	T &operator[](unsigned int index)
	{
		if (index >= this->_size)
			throw Array::OutOfBoundsException();
		return (this->_arr[index]);
	}
	const T &operator[](unsigned int index) const
	{
		if (index >= this->_size)
			throw Array::OutOfBoundsException();
		return (this->_arr[index]);
	}
	unsigned int size() const
	{
		return this->_size;
	}
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Index is out of bounds!";
		}
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &arr)
{
	os<<"[ ";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		os << "index" << i << ": " << arr[i] << " ";
	}
	os << "]" << std::endl;
	return os;
}

#endif