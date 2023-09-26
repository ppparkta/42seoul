#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void iter(T *arr, size_t size, void (*function)(T &target))
{
	if (arr == NULL || size == 0 || function == NULL)
		return;
	for (size_t i = 0; i < size; i++)
		function(arr[i]);
}

template <typename T>
void iter(const T *arr, const size_t size, void (*function)(T const &target))
{
	if (arr == NULL || size == 0 || function == NULL)
		return;
	for (size_t i = 0; i < size; i++)
		function(arr[i]);
}


template <typename T>
void test_func(T &target)
{
	target += 2;
}

#endif