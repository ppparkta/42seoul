
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "Test 1" << std::endl;
	{
		Bureaucrat	a("a", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("presidential pardon", "b");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << *b;
		delete b;
		std::cout << std::endl;
	}


	std::cout << "Test 2" << std::endl;
	{
		Bureaucrat	a("a", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("robotomy request", "b");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << *b;
		delete b;
		std::cout << std::endl;
	}


	std::cout << "Test 3" << std::endl;
	{
		Bureaucrat	a("a", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("shrubbery creation", "b");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << *b;
		delete b;
		std::cout << std::endl;
	}

	
	std::cout << "Test 4" << std::endl;
	{
		Bureaucrat	a("a", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("go to home", "b");
			a.signForm(*b);
			a.executeForm(*b);
			delete b;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}