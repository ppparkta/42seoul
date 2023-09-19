#include "Bureaucrat.hpp"

int main()
{
    {
		std::cout << "Test 1" << std::endl;
		Bureaucrat a;
        Bureaucrat b("sooyang", 2);
		std::cout << a;
        std::cout << b;
		try
		{
			a.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			a.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << a;

		try
		{
			 b.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			  b.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;
	}
}