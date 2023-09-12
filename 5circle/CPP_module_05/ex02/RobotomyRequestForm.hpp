#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(RobotomyRequestForm &form);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

        std::string getTarget() const;
}

std::ostream &operator <<(std::ostream &os, RobotomyRequestForm &form);

#endif