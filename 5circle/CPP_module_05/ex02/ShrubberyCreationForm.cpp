#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm",145,137){
    this->target="default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):AForm("ShrubberyCreationForm",145,137){
    this->target=target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form){
    *this=form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form){
    if (this!=&form)
        this->target=form.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget() const{
    return this->target;
}

void ShrubberyCreationForm::exec() const{
    std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());
    outfile<<
    "    .-"<<std::endl<<
    "   -::;"<<std::endl<<
    "   ::::"<<std::endl<<
    "  ~:::::"<<std::endl<<
    "  ::::::"<<std::endl<<
    "  ::::::."<<std::endl<<
    " -:::::::"<<std::endl<<
    " ::::::::"<<std::endl<<
    " ::::::::"<<std::endl<<
    " -:::::::"<<std::endl<<
    "  ::::::"<<std::endl<<
    "    !!"<<std::endl<<
    "    ##"<<std::endl<<
    "    ##"<<std::endl<<std::endl;

    outfile.close();
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &form){
    return os<<"form: "<<form.getName()<<", execute grade: "<<form.getExecuteGrade()<<", signed grade: "<<form.getSignGrade()<<", signed? "<<form.getIsSigned()<<", target: "<<form.getTarget()<<std::endl;
}