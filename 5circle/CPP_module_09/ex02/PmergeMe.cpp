#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_vector(const std::vector<int> &args)
{
	std::vector<std::vector<int> > pair;
	for (int i = 0; i + 1 < args.size(); i += 2)
	{
		pair.push_back(std::vector<int>());
		pair.back().push_back(std::max(args[i], args[i + 1]));
		pair.back().push_back(std::min(args[i], args[i + 1]));
	}
	for (std::vector<std::vector<int> >::iterator iter = pair.begin(); iter != pair.end(); iter++)
	{
		for (std::vector<std::vector<int> >::iterator tmp = iter; tmp != pair.end(); tmp++)
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

void PmergeMe::insertion_sort_vec(){
	initialize_index();
	if (this->pendingElements_vec.size() != 0) 
		this->mainChain_vec.insert(this->mainChain_vec.begin(), this->pendingElements_vec[0]);
	//print_vector();
	int i = 1;
	while(i < this->pendingElements_vec.size()){
		int num = this->index.back();
		//std::cout<<"index number = "<<num<<std::endl;
		int j = (i + num < this->pendingElements_vec.size()) ? i + num : this->pendingElements_vec.size();
		for (int k = i; i <= --j ; k++) {
			//std::cout<<"i = "<<i<<", k = "<<k<<", j = "<<j<<", pendingE[j] = "<<this->pendingElements_vec[j]<<std::endl;
			this->mainChain_vec.insert(std::upper_bound(this->mainChain_vec.begin(), this->mainChain_vec.begin() + j + k, this->pendingElements_vec[j]),\
				this->pendingElements_vec[j]);
			//print_vector();
		}
		//std::cout<<std::endl;
		i += num;
		find_next_insertion();
	}
}

void PmergeMe::print_vector(){
	std::cout<<"=================================="<<std::endl;
	std::cout<<"(vector) mainChain: ";
	for(int i=0;i<this->mainChain_vec.size();i++){
		std::cout<<this->mainChain_vec[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"(vector) pending_e: ";
	for(int i=0;i<this->pendingElements_vec.size();i++){
		std::cout<<this->pendingElements_vec[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"=================================="<<std::endl;
}

void PmergeMe::merge_insertion_sort_vec(const std::vector<int> &args){
	merge_vector(args);
	insertion_sort_vec();
}

void PmergeMe::merge_list(const std::vector<int> &args)
{
	std::list<std::list<int> > pair;
	for (int i = 0; i + 1 < args.size(); i += 2)
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

void PmergeMe::insertion_sort_lst(){
	initialize_index();
	print_list();
	if (this->pendingElements_lst.size() != 0) 
		this->mainChain_lst.insert(this->mainChain_lst.begin(), *this->pendingElements_lst.begin());
	print_list();
	int i = 1;
	while(i < this->pendingElements_lst.size()){
		int num = this->index.back();
		//std::cout<<"index number = "<<num<<std::endl;
		int j = (i + num < this->pendingElements_lst.size()) ? i + num : this->pendingElements_lst.size();
		for (int k = i; i <= --j ; k++) {
			//std::cout<<"i = "<<i<<", k = "<<k<<", j = "<<j<<", pendingE[j] = "<<this->pendingElements_vec[j]<<std::endl;
			//this->mainChain_lst.insert(std::upper_bound(this->mainChain_lst.begin(), (this->mainChain_lst.begin() + j + k), *(this->pendingElements_lst.begin() + j)),\
			//	this->pendingElements_vec[j]);
			//print_vector();
		}
		//std::cout<<std::endl;
		i += num;
		find_next_insertion();
	}
}

void PmergeMe::print_list(){
	std::cout<<"=================================="<<std::endl;
	std::cout<<"(list) mainChain: ";
	for(std::list<int>::iterator i = this->mainChain_lst.begin(); i != this->mainChain_lst.end(); i++){
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"(list) pending_e: ";
	for(std::list<int>::iterator i = this->pendingElements_lst.begin(); i != this->pendingElements_lst.end(); i++){
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"=================================="<<std::endl;
}

void PmergeMe::merge_insertion_sort_lst(const std::vector<int> &args){
	merge_list(args);
	insertion_sort_lst();
}

void PmergeMe::initialize_index(){
	this->index.clear();
	this->index.push_back(1);
	this->index.push_back(3);
}

void PmergeMe::find_next_insertion(){
	this->index.push_back(index[index.size()-1] + (2 * index[index.size() - 2]));
}

static void check_args(int argc, char **argv, std::vector<int> &args)
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
	check_args(argc, argv, args);
	std::vector<int> save_args(args);

	std::cout << "Before: ";
	for (int i = 0; i < save_args.size(); i++)
	{
		std::cout << save_args[i] << " ";
		if (i == save_args.size() - 1)
			std::cout<<std::endl;
	}

	sort(args.begin(), args.end());
	std::cout<<"After: ";
	for(int i=0;i<args.size();i++){
		std::cout << args[i] << " ";
		if (i == args.size() - 1)
			std::cout<<std::endl;
	}

	clock_t start_vec, finish_vec, start_lst, finish_lst;

	start_vec = clock();
	merge_insertion_sort_vec(save_args);
	finish_vec = clock();

	start_lst = clock();
	merge_insertion_sort_lst(save_args);
	finish_lst = clock();

	std::cout<<"Time to process a range of "<< save_args.size() << " elements with std::vector : "<<finish_vec-start_vec<<" ms"<<std::endl;
	std::cout<<"Time to process a range of "<< save_args.size() << " elements with std::list : "<<finish_lst-start_lst<<" ms"<<std::endl;
}