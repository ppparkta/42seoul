#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> mainChain_vec;
		std::vector<int> pendingElements_vec;
		std::list<int> mainChain_lst;
		std::list<int> pendingElements_lst;

		PmergeMe(const PmergeMe &pmerge);
		PmergeMe &operator=(const PmergeMe &pmerge);

	public:
		PmergeMe();
		~PmergeMe();

		void merge_vector(const std::vector<int> &args);
		void merge_list(const std::vector<int> &args);
		void merge(int argc, char **argv);
};



#endif