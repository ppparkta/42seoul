#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "Test 1" << std::endl;
	Bureaucrat	a("Newhire", 150);
	Bureaucrat	b("Project Lead", 40);
	Bureaucrat	c("Director", 3);
	Bureaucrat	d("Employee", 100);
	PresidentialPardonForm pardon("Jibby");
	RobotomyRequestForm	robo("Cop");
	ShrubberyCreationForm tree("Park");
	std::cout << a;
	std::cout << d;
	std::cout << b;
	std::cout << c;
	std::cout << pardon;
	std::cout << robo;
	std::cout << tree;
	std::cout << std::endl;
	std::cout << "Test 1" << std::endl;
	{
		a.signForm(pardon);
		d.signForm(pardon);
		b.signForm(pardon);
		c.signForm(pardon);
		a.executeForm(pardon);
		d.executeForm(pardon);
		b.executeForm(pardon);
		c.executeForm(pardon);
		std::cout << std::endl;
	}
	std::cout << "Test 2" << std::endl;
	{
		c.executeForm(robo);
		a.signForm(robo);
		d.signForm(robo);
		b.signForm(robo);
		c.signForm(robo);
		a.executeForm(robo);
		d.executeForm(robo);
		b.executeForm(robo);
		c.executeForm(robo);
		std::cout << std::endl;
	}
	std::cout << "Test 3" << std::endl;
	{
		d.executeForm(tree);
		a.signForm(tree);
		d.signForm(tree);
		b.signForm(tree);
		c.signForm(tree);
		a.executeForm(tree);
		d.executeForm(tree);
		b.executeForm(tree);
		c.executeForm(tree);
		std::cout << std::endl;
	}
	return (0);
}