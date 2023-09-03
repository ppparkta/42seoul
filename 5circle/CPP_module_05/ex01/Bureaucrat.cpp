#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default_name"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
    if (grade>150) throw Bureaucrat::GradeTooLowException();
    else if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = bur;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bur)
{
    if (this != &bur){
        this->grade = bur.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &bur){
    return os <<bur.getName()<<", bureaucrat grade "<<bur.getGrade()<<"."<<std::endl;
}

const std::string Bureaucrat::getName(void) const { return this->name; }

const int Bureaucrat::getGrade(void) const{ return this->grade; }

void Bureaucrat::increaseGrade(void){
    if (this->grade <= 1){
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
    std::cout<<"increment the "<<this->name<<"'s grade. (now: "<<this->grade<<")"<<std::endl;
}

void Bureaucrat::decreaseGrade(void){
    if (this->grade >= 150){
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
    std::cout<<"decrement the "<<this->name<<"'s grade. (now: "<<this->grade<<")"<<std::endl;
}

void Bureaucrat::signForm(Form &form){
    try{
        form.beSigned(*this);
    }
    catch(const std::exception &e){
        std::cout << this->getName() << " couldn't sign the " << form.getName() << " because grade is too low" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "grade is out of range. Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "grade is out of range. Grade is too low!";
}
