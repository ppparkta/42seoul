#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &form);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
        ~ShrubberyCreationForm();

        std::string getTarget() const;
        void exec() const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &form);

#endif
