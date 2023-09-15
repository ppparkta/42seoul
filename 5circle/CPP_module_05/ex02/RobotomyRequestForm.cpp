#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72,45){
	this->target="default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):AForm("RobotomyRequestForm",72,45){
	this->target=target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form){
	*this=form;
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm &form){
	if (this != &form)
		this->target=form.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget() const{
	return this->target;
}

void RobotomyRequestForm::exec() const {
	std::srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout<<"drillingdrillingdrillingdrillingdrilling "<<this->target<<" has been robotomized successfully."<<std::endl;
	else
		std::cout<<this->target<<" robotomy failed."<<std::endl;
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &form){
	return os<<"form: "<<form.getName()<<", execute grade: "<<form.getExecuteGrade()<<", signed grade: "<<form.getSignGrade()<<", signed? "<<form.getIsSigned()<<", target: "<<form.getTarget()<<std::endl;
}