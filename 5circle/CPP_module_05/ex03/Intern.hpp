#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern &operator=(const Intern &intern);
		AForm *makeForm(std::string name, std::string target);

		class NotMatchException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif