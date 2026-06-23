
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name_Aform("default"), grade_TO_SIN(150), grade_TO_EX(150) {}

AForm::AForm(const std::string &Name, const int &G_tosing, const int &G_EX) : name_Aform(Name), grade_TO_SIN(G_tosing), grade_TO_EX(G_EX)
{
    Indicating_Sig = false;
    
    if (getGradeSin() > 150 || getGradeEx() > 150)
        throw GradeTooLowException();
    if (getGradeSin() < 1 || getGradeEx() < 1)
        throw GradeTooHighException();
        
}

AForm::AForm(const AForm &other)
    : name_Aform(other.name_Aform),
      Indicating_Sig(other.Indicating_Sig),
      grade_TO_SIN(other.grade_TO_SIN),
      grade_TO_EX(other.grade_TO_EX){}

AForm & AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->Indicating_Sig = other.Indicating_Sig;
    }
    return *this;
}

std::string AForm::getName() const
{
    return name_Aform;
}
bool AForm::getIndication_Sin() const
{
    return Indicating_Sig;
}
int AForm::getGradeSin() const
{
    return grade_TO_SIN;
}
int AForm::getGradeEx() const
{   
    return grade_TO_EX;
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char *AForm::GradeTooLowException::what()  const throw() { return "Grade too low!"; }

const char *AForm::GradeOrSingExpaction::what() const throw() { return "Grade to low or the form dos not singed!";}

///members
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeSin())
        this->Indicating_Sig = true;
    else
        throw GradeTooLowException();
}
AForm::~AForm() {}
// operators

std::ostream& operator<<(std::ostream &os, const AForm &obj)
{
    os << "AForm name: " <<obj.getName() << "\nSigned: " << obj.getIndication_Sin() << "\nGrade required to sign: "<< obj.getGradeSin() << "\nGrade required to execute: " << obj.getGradeEx() ; 
    return os;
}


