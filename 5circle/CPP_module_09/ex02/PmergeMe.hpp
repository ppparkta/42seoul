#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <time.h>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<size_t> index;
		std::vector<size_t> mainChain_vec;
		std::vector<size_t> pendingElements_vec;
		std::list<size_t> mainChain_lst;
		std::list<size_t> pendingElements_lst;

		PmergeMe(const PmergeMe &pmerge);
		PmergeMe &operator=(const PmergeMe &pmerge);

		void merge_insertion_sort_vec(const std::vector<size_t> &args);
		void merge_insertion_sort_lst(const std::vector<size_t> &args);
		void insertion_sort_vec();
		void insertion_sort_lst();
		void merge_vector(const std::vector<size_t> &args);
		void merge_list(const std::vector<size_t> &args);
		void initialize_index();
		void find_next_insertion();
		
		void print_vector();
		void print_list();

	public:
		PmergeMe();
		~PmergeMe();

		void merge(int argc, char **argv);
};

#endif