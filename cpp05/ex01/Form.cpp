
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name_form("default"), Indicating_Sig(false), grade_TO_SIN(150),  grade_TO_EX(150) {}

Form::Form(const std::string &Name, const int &G_tosing, const int &G_EX) : name_form(Name), grade_TO_SIN(G_tosing), grade_TO_EX(G_EX)
{
    Indicating_Sig = false;
    
    if (getGradeSin() > 150 || getGradeEx() > 150)
    {
        throw GradeTooLowException();
    }
    if (getGradeSin() < 1 || getGradeEx() < 1)
    {
        throw GradeTooHighException();
    }
}

Form::Form(const Form &other)
    : name_form(other.name_form),
      Indicating_Sig(other.Indicating_Sig),
      grade_TO_SIN(other.grade_TO_SIN),
      grade_TO_EX(other.grade_TO_EX){}

Form & Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->Indicating_Sig = other.Indicating_Sig;
    }
    return *this;
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

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char *Form::GradeTooLowException::what()  const throw() { return "Grade too low!"; }


void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeSin())
        this->Indicating_Sig = true;
    else
        throw GradeTooLowException();
}
Form::~Form() {}


std::ostream& operator<<(std::ostream &os, const Form &obj)
{
    os << "Form name: " <<obj.getName() << "\n\tSigned: " << obj.getIndication_Sin() << "\n\tGrade required to sign: "<< obj.getGradeSin() << "\n\tGrade required to execute: " << obj.getGradeEx() ; 
    return os;
}


