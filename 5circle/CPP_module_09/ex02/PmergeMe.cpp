#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_vector(const std::vector<size_t> &args)
{
	std::vector<std::vector<size_t> > pair;
	for (int i = 0; i + 1 < args.size(); i += 2)
	{
		pair.push_back(std::vector<size_t>());
		pair.back().push_back(std::max(args[i], args[i + 1]));
		pair.back().push_back(std::min(args[i], args[i + 1]));
	}
	for (std::vector<std::vector<size_t> >::iterator iter = pair.begin(); iter != pair.end(); iter++)
	{
		for (std::vector<std::vector<size_t> >::iterator tmp = iter; tmp != pair.end(); tmp++)
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

void PmergeMe::insertion_sort_vec()
{
	initialize_index();
	if (!this->pendingElements_vec.empty())
		this->mainChain_vec.insert(this->mainChain_vec.begin(), this->pendingElements_vec[0]);
	int now = 1;
	while (now < this->pendingElements_vec.size())
	{
		int bind_point = this->index.back();
		// std::cout<<"bind_point = "<<bind_point<<std::endl;
		int j = (now + bind_point < this->pendingElements_vec.size()) ? now + bind_point : this->pendingElements_vec.size();
		for (int k = now; now <= --j; k++)
		{
			// std::cout<<"now = "<<now<<", k = "<<k<<", j = "<<j<<", pendingE[j] = "<<this->pendingElements_vec[j]<<std::endl;
			this->mainChain_vec.insert(std::upper_bound(this->mainChain_vec.begin(), this->mainChain_vec.begin() + j + k, this->pendingElements_vec[j]),
									   this->pendingElements_vec[j]);
		}
		now += bind_point;
		find_next_insertion();
	}
	//print_vector();
}

void PmergeMe::print_vector()
{
	std::cout << "==================================" << std::endl;
	std::cout << "(vector) mainChain: ";
	for (int i = 0; i < this->mainChain_vec.size(); i++)
	{
		std::cout << this->mainChain_vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "(vector) pending_e: ";
	for (int i = 0; i < this->pendingElements_vec.size(); i++)
	{
		std::cout << this->pendingElements_vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "==================================" << std::endl;
}

void PmergeMe::merge_insertion_sort_vec(const std::vector<size_t> &args)
{
	merge_vector(args);
	insertion_sort_vec();
}

void PmergeMe::merge_list(const std::vector<size_t> &args)
{
	std::list<std::list<size_t> > pair;
	for (int i = 0; i + 1 < args.size(); i += 2)
	{
		pair.push_back(std::list<size_t>());
		pair.back().push_back(std::max(args[i], args[i + 1]));
		pair.back().push_back(std::min(args[i], args[i + 1]));
	}
	for (std::list<std::list<size_t> >::iterator iter = pair.begin(); iter != pair.end(); iter++)
	{
		for (std::list<std::list<size_t> >::iterator tmp = iter; ++tmp != pair.end();)
		{
			if (*iter > *tmp)
				std::swap(*iter, *tmp);
		}
	}
	for (int i = pair.size(); 0 < i; i--)
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

void PmergeMe::insertion_sort_lst()
{
	initialize_index();
	if (!pendingElements_lst.empty())
	{
		mainChain_lst.insert(mainChain_lst.begin(), pendingElements_lst.front());
		pendingElements_lst.pop_front();
	}
	int now = 1;
	while (!pendingElements_lst.empty())
	{
		int bind_point = (index.back() < pendingElements_lst.size()) ? index.back() : pendingElements_lst.size();
		find_next_insertion();
		now += bind_point;
		//std::cout<<"bind_point: "<<bind_point<<std::endl;

		std::list<size_t> tmp;
		while (bind_point--)
		{
			tmp.push_front(pendingElements_lst.front());
			pendingElements_lst.pop_front();
		}

		std::list<size_t>::iterator iter = mainChain_lst.begin();
		for (int i = 0; i < now; i++)
			iter++;
		now += tmp.size();

		while (!tmp.empty())
		{
			std::list<size_t>::iterator insert_e = std::upper_bound(mainChain_lst.begin(), iter, tmp.front());
			mainChain_lst.insert(insert_e, tmp.front());
			tmp.pop_front();
			if (insert_e == iter)
				iter--;
		}
	}
	//print_list();
}

void PmergeMe::print_list()
{
	std::cout << "==================================" << std::endl;
	std::cout << "(list) mainChain: ";
	for (std::list<size_t>::iterator i = this->mainChain_lst.begin(); i != this->mainChain_lst.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "(list) pending_e: ";
	for (std::list<size_t>::iterator i = this->pendingElements_lst.begin(); i != this->pendingElements_lst.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "==================================" << std::endl;
}

void PmergeMe::merge_insertion_sort_lst(const std::vector<size_t> &args)
{
	merge_list(args);
	insertion_sort_lst();
}

void PmergeMe::initialize_index()
{
	this->index.clear();
	this->index.push_back(1);
	this->index.push_back(3);
}

void PmergeMe::find_next_insertion()
{
	this->index.push_back(index[index.size() - 1] + (2 * index[index.size() - 2]));
}

static void check_args(int argc, char **argv, std::vector<size_t> &args)
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
	std::vector<size_t> args;
	check_args(argc, argv, args);
	std::vector<size_t> save_args(args);

	std::cout << "Before: ";
	for (int i = 0; i < save_args.size(); i++)
	{
		std::cout << save_args[i] << " ";
		if (i == save_args.size() - 1)
			std::cout << std::endl;
	}

	sort(args.begin(), args.end());
	std::cout << "After: ";
	for (int i = 0; i < args.size(); i++)
	{
		std::cout << args[i] << " ";
		if (i == args.size() - 1)
			std::cout << std::endl;
	}

	clock_t start_vec, finish_vec, start_lst, finish_lst;

	start_vec = clock();
	merge_insertion_sort_vec(save_args);
	finish_vec = clock();

	start_lst = clock();
	merge_insertion_sort_lst(save_args);
	finish_lst = clock();

	std::cout << "Time to process a range of " << save_args.size() << " elements with std::vector : " << finish_vec - start_vec << " ms" << std::endl;
	std::cout << "Time to process a range of " << save_args.size() << " elements with std::list : " << finish_lst - start_lst << " ms" << std::endl;
}