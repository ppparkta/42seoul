#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP_

#include <iostream>
#include <exception>

class Exeption {
	public:
}

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &bur);
		Bureaucrat& operator =(const Bureaucrat &bur);
		const std::string getName(void) const;
		const int getGrade(void) const;
}

# endif