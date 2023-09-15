#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int execute_grade;

	public:
		AForm();
		AForm(const std::string name, int sign_grade, int execute_grade);
		AForm(const AForm &form);
		AForm& operator =(const AForm &form);
		virtual ~AForm();

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		virtual void exec(void) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &bur);
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator <<(std::ostream& os, AForm &form);

#endif