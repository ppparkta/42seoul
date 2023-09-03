#include "Bureaucrat.hpp"

int main()
{
	//기본 예외처리 테스트
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

	//복사생성자, 대입연산자 예외처리 테스트
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat a("ect", 150);
		std::cout << a;
		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		Bureaucrat b(a);
        std::cout << b;
		std::cout << a;
		try
		{
			b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			  b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			 b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << b;
        std::cout << a;

		Bureaucrat c;
		c = a;
		std::cout << c;
        std::cout << a;
		try
		{
			c.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			c.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << c;
		std::cout << b;
        std::cout << a;
		std::cout << std::endl;
	}
}