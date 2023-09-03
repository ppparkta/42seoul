#include "Form.hpp"

Form::Form():name("default_name"),is_signed(false),sign_grade(150),execute_grade(150){}

Form::Form(const std::string name, int sign_grade, int execute_grade):name(name),is_signed(false),sign_grade(sign_grade),execute_grade(execute_grade){
	if (sign_grade < 1 || execute_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form):name(form.name),sign_grade(form.sign_grade),execute_grade(form.execute_grade){
	std::cout << "Copy constructor called" << std::endl;
	*this = form;
}

Form& Form::operator =(const Form &form){
	if (this != &form)
		this->is_signed=form.is_signed;
	return *this;
}

Form::~Form(){}

std::string Form::getName(void) const{ return this->name; }

bool Form::getIsSigned(void) const{ return this->is_signed; }

int Form::getSignGrade(void) const{ return this->sign_grade; }

int Form::getExecuteGrade(void) const{ return this->execute_grade; }

const char *Form::GradeTooHighException::what() const throw(){
	return "grade is out of range. Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "grade is out of range. Grade is too low!";
}
std::ostream &operator<<(std::ostream &os, Form &form){
	return os<<form.getName()<<", is_signed: "<<form.getIsSigned()<<", sign_grade: "<<form.getSignGrade()<<", execute_grade: "<<form.getExecuteGrade()<<std::endl;
}

void Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() > this->getSignGrade()){
		throw Form::GradeTooLowException();
	}
	if (this->is_signed == false)
	{
		this->is_signed = true;
		std::cout<<bur.getName()<<" signed "<<this->getName()<<std::endl;
	}
	else
		std::cout<<bur.getName()<<" couldn’t sign "<<this->getName()<<" because already signed."<<std::endl;
}