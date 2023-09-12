#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &form);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
        ~PresidentialPardonForm();

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
}

std::ostream& operator <<(std::ostream &os, PresidentialPardonForm &form); 

#endif