#include "AForm.hpp"

AForm::AForm():name("default_name"),is_signed(false),sign_grade(150),execute_grade(150){}

AForm::AForm(const std::string name, int sign_grade, int execute_grade):name(name),is_signed(false),sign_grade(sign_grade),execute_grade(execute_grade){
	if (sign_grade < 1 || execute_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form):name(form.name),sign_grade(form.sign_grade),execute_grade(form.execute_grade){
	std::cout << "Copy constructor called" << std::endl;
	*this = form;
}

AForm& AForm::operator =(const AForm &form){
	if (this != &form)
		this->is_signed=form.is_signed;
	return *this;
}

AForm::~AForm(){}

std::string AForm::getName(void) const{ return this->name; }

bool AForm::getIsSigned(void) const{ return this->is_signed; }

int AForm::getSignGrade(void) const{ return this->sign_grade; }

int AForm::getExecuteGrade(void) const{ return this->execute_grade; }

const char *AForm::GradeTooHighException::what() const throw(){
	return "grade is out of range. Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw(){
	return "grade is out of range. Grade is too low!";
}
std::ostream &operator<<(std::ostream &os, AForm &form){
	return os<<form.getName()<<", is_signed: "<<form.getIsSigned()<<", sign_grade: "<<form.getSignGrade()<<", execute_grade: "<<form.getExecuteGrade()<<std::endl;
}

void AForm::beSigned(Bureaucrat &bur){
	if (bur.getGrade() > this->getSignGrade()){
		throw AForm::GradeTooLowException();
	}
	if (this->is_signed == false)
	{
		this->is_signed = true;
		std::cout<<bur.getName()<<" signed "<<this->getName()<<std::endl;
	}
	else
		std::cout<<bur.getName()<<" couldn’t sign "<<this->getName()<<" because already signed."<<std::endl;
}