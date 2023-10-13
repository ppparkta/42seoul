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
		std::vector<int> index;
		std::vector<int> mainChain_vec;
		std::vector<int> pendingElements_vec;
		std::list<int> mainChain_lst;
		std::list<int> pendingElements_lst;

		PmergeMe(const PmergeMe &pmerge);
		PmergeMe &operator=(const PmergeMe &pmerge);

		void merge_insertion_sort_vec(const std::vector<int> &args);
		void merge_insertion_sort_lst(const std::vector<int> &args);
		void insertion_sort_vec();
		void insertion_sort_lst();
		void merge_vector(const std::vector<int> &args);
		void merge_list(const std::vector<int> &args);
		void initialize_index();
		void find_next_insertion();

	public:
		PmergeMe();
		~PmergeMe();

		void merge(int argc, char **argv);
};

#endif