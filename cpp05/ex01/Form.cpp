
#include "Form.hpp"

Form::Form() : name_form("default"), grade_TO_EX(150), grade_TO_SIN(150) {}

Form::Form(std::string &Name, const int &G_tosing, const int &G_EX) : name_form(Name), grade_TO_EX(G_EX), grade_TO_SIN(G_tosing)
{
    Indicating_Sig = false;
    
    if (getGradeSin() > 150 || getGradeEx() > 150)
    {
        throw GradeTooHighException();
    }
    if (getGradeEx() < 1 || getGradeEx() < 1)
    {
        throw GradeTooLowException();
    }
}



std::string Form::getName() const
{
    return name_form;
}
bool Form::getIndication_Sin() const
{
    return Indicating_Sig;
}
int Form::getGradeSin() const
{
    return grade_TO_SIN;
}
int Form::getGradeEx() const
{   
    return grade_TO_EX;
}

///members 
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < this->getGradeSin())
        this->Indicating_Sig = true;
    else
        throw GradeTooLowException();
}
Form::~Form(){}
// operators

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
    os << " Form name: " <<obj.getName() << "\n Signed: " << obj.getIndication_Sin() << "\nGrade required to sign: "<< obj.getGradeSin() << "/nGrade required to execute: " << obj.getGradeEx() ; 
}


