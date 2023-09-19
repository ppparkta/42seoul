#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat	a("a", 150);
	Bureaucrat	b("b", 40);
	Bureaucrat	c("c", 3);
	Bureaucrat	d("d", 100);
	PresidentialPardonForm pardon("pardon");
	RobotomyRequestForm	robo("robo");
	ShrubberyCreationForm tree("tree");
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	std::cout << pardon;
	std::cout << robo;
	std::cout << tree;
	std::cout << std::endl;


	std::cout << "Test 1" << std::endl;
	{
		a.signForm(pardon);
		b.signForm(pardon);
		c.signForm(pardon);
		d.signForm(pardon);
		std::cout<<std::endl;

		a.executeForm(pardon);
		b.executeForm(pardon);
		c.executeForm(pardon);
		d.executeForm(pardon);
		std::cout << std::endl;
	}


	std::cout << "Test 2" << std::endl;
	{
		c.executeForm(robo);
		a.signForm(robo);
		d.signForm(robo);
		b.signForm(robo);
		c.signForm(robo);
		std::cout<<std::endl;
		
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
		std::cout<<std::endl;
		
		a.executeForm(tree);
		d.executeForm(tree);
		b.executeForm(tree);
		c.executeForm(tree);
		std::cout << std::endl;
	}
	
	return (0);
}