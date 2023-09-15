#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &intern){
	*this=intern;
}

Intern::~Intern(){}

Intern& Intern::operator=(const Intern &intern){
	return *this;
}

const char *Intern::NotMatchException::what() const throw(){
	return "There is no form that matches the name.";
}

static AForm *makePresident(const std::string target){
	return new PresidentialPardonForm(target);
}

static AForm *makeRobot(const std::string target){
	return new RobotomyRequestForm(target);
}

static AForm *makeShrubbery(const std::string target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target){
	AForm *makeForms[3] = {makePresident(target), makeRobot(target), makeShrubbery(target)};
	const std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *cur = NULL;
	for (int i=0;i<3;i++){
		if (name == forms[i])
		{
			std::cout<<"Intern creates "<<name<<std::endl;
			cur = makeForms[i];
		}
		else
			delete makeForms[i];
	}
	if (cur == NULL)
		throw Intern::NotMatchException();
	return cur;
}