#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default_name"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade>150) throw GradeTooLowException;
    else if (grade < 1) throw GradeTooLowException;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
    *this = bur;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bur)
{
    if (this != &bur)
    {
        this->grade = bur.grade;
        this->name = bur.name;
    }
    return *this;
}

ostream& Bureaucrat::operator <<(std::ostream &os, Bureaucrat &bur){
    return os <<bur->name<<", bureaucrat grade"<<bur->grade<<"."<<std::endl;
}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

const int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

Bureaucrat::GradeTooHighException(void){

}

Bureaucrat::GradeTooLowException(void){

}