#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default_name"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
    *this = bur;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
    if (this != &bur)
    {
        this->grade = bur.grade;
        this->name = bur.name;
    }
    return *this;
}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

const int Bureaucrat::getGrade(void) const
{
    return this->grade;
}