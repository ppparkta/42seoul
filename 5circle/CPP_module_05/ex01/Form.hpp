#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int execute_grade;

	public:
		Form();
		Form(const std::string name, int sign_grade, int execute_grade);
		Form(const Form &form);
		Form& operator =(const Form &form);
		~Form();

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;

		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &bur);
};

std::ostream& operator <<(std::ostream& os, Form &form);

#endif