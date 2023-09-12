#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP_

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &bur);
		~Bureaucrat();
		Bureaucrat& operator =(const Bureaucrat &bur);
	
		const std::string getName(void) const;
		const int getGrade(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void signForm(AForm &form);
		void executeForm(AForm const &form);
};

std::ostream& operator <<(std::ostream &os, Bureaucrat &bur);

# endif