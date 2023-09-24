#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename T>
void iter(T *arr, size_t size, void (*function)(T &target)){
	if (arr == NULL || size == 0 || f == NULL){
		return ;
	}
	for (size_t i = 0; i < size; i++){
		function(arr[i]);
	}
}

#endif