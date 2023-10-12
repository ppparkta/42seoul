#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_vector(const std::vector<int> &args)
{
	std::vector<std::vector<int> > pair;
	for (int i = 0; i < i + 1 < args.size(); i += 2)
	{
		pair.push_back(std::vector<int>());
		pair.back().push_back(std::max(args[i], args[i + 1]));
		pair.back().push_back(std::min(args[i], args[i + 1]));
	}
	for (std::vector<std::vector<int> >::iterator iter = pair.begin(); iter != pair.end(); iter++)
	{
		for (std::vector<std::vector<int> >::iterator tmp = iter; ++tmp != pair.end();)
		{
			if (*iter > *tmp)
				std::swap(*iter, *tmp);
		}
	}
	for (int i = 0; i < pair.size(); i++)
	{
		this->mainChain_vec.push_back(pair[i][0]);
		this->pendingElements_vec.push_back(pair[i][1]);
	}
	if (args.size() % 2 == 1)
		this->pendingElements_vec.push_back(args.back());
}

void PmergeMe::merge_list(const std::vector<int> &args)
{
	std::list<std::list<int> > pair;
	for (int i = 0; i < i + 1 < args.size(); i += 2)
	{
		pair.push_back(std::list<int>());
		pair.back().push_back(std::max(args[i], args[i + 1]));
		pair.back().push_back(std::min(args[i], args[i + 1]));
	}
	for (std::list<std::list<int> >::iterator iter = pair.begin(); iter != pair.end(); iter++)
	{
		for (std::list<std::list<int> >::iterator tmp = iter; ++tmp != pair.end();)
		{
			if (*iter > *tmp)
				std::swap(*iter, *tmp);
		}
	}
	for (int i = pair.size();; i--)
	{
		this->mainChain_lst.push_back(pair.front().front());
		pair.front().pop_front();
		this->pendingElements_lst.push_back(pair.front().front());
		pair.front().pop_front();
		pair.pop_front();
	}
	if (args.size() % 2 == 1)
		this->pendingElements_lst.push_back(args.back());
}

static void check_insertion_args(int argc, char **argv, std::vector<int> &args)
{
	std::string str;
	for (int i = 1; i < argc; i++)
	{
		str += argv[i];
		str += ' ';
	}
	bool check = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			if (!check)
			{
				check = true;
				args.push_back(int());
			}
			args.back() = args.back() * 10 + (str[i] - '0');
		}
		else if (isspace(str[i]))
			check = false;
		else
			throw std::invalid_argument("Error");
	}
}

void PmergeMe::merge(int argc, char **argv)
{
	std::vector<int> args;
	check_insertion_args(argc, argv, args);
	std::vector<int> save_args(args);
}