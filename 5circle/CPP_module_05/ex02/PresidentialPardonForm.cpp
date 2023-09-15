#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",25,5){
	this->target="default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("PresidentialPardonForm",25,5){
	this->target=target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form){
	*this=form;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form){
	if (this!=&form)
		this->target=form.target;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->target;
}

void PresidentialPardonForm::exec() const{
	std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

std::ostream& operator <<(std::ostream &os, PresidentialPardonForm &form){
	return os<<"form: "<<form.getName()<<", execute grade: "<<form.getExecuteGrade()<<", signed grade: "<<form.getSignGrade()<<", signed? "<<form.getIsSigned()<<", target: "<<form.getTarget()<<std::endl;
}