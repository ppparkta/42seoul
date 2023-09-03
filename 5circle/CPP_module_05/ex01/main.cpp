#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	//싸인 성공, 이미 싸인한 경우 예외처리
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat a;
		Form b;
		std::cout << a;
		std::cout << b;

		try
		{
			b.beSigned(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			b.beSigned(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << b;
		std::cout << std::endl;
	}

	//싸인 성공, 관료등급이 낮은 경우 예외처리
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat a("ect", 135);
		Bureaucrat b("sooyang", 1);
		Form c("cpp_module_05", 100, 130);

		std::cout << a;
		std::cout << b;
		std::cout << c;
		
		try
		{
			a.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << c;
		try
		{
			c.beSigned(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << c;

		try
		{
			b.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	//
	{
		std::cout << "Test 3" << std::endl;
		try
		{
			Form a("A", 160, 145);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form a("B",145, 160);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form a("C", 1, -1);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			Form a("D", 0, 12);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}