#include "easyfind.hpp"

int main(void)
{
	{
		std::cout << "test1 (vector)" << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i + 1);
		}
		try
		{
			std::vector<int>::iterator i = easyfind(v, 1);
			std::cout << "iterator i's value: " << *i << std::endl;
			i = easyfind(v, 15);
			std::cout << "iterator i's value: " << *i << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		std::cout << "test2 (list)" << std::endl;
		std::list<int> l;
		for (int i = 0; i < 10; i++)
		{
			l.push_back(i + 1);
		}
		try
		{
			std::list<int>::iterator l_i = easyfind(l, 5);
			std::cout << "iterator i's value: " << *l_i << std::endl;
			l_i = easyfind(l, 15);
			std::cout << "iterator i's value: " << *l_i << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
}