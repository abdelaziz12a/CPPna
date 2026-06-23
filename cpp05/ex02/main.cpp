
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>
         
         
int main()
{
    srand(time(0));
    try 
    {
        Bureaucrat high("High", 0);     //powerfal
        Bureaucrat mid("Mid", 45);      // midume
        Bureaucrat low("Low", 150);      //week

        try
        {
            ShrubberyCreationForm shrub("home");
            high.signForm(shrub);
            high.executeForm(shrub);
        }
        catch (std::exception &e)
        {
            std::cout << "Shrubbery error: " << e.what() << std::endl;
        }

        std::cout << "---------------------\n";

        try
        {
            RobotomyRequestForm robot("Bender");
            mid.signForm(robot);    
            mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
            // mid.executeForm(robot); 
        }
        catch (std::exception &e)
        {
            std::cout << "Robotomy error: " << e.what() << std::endl;
        }

        std::cout << "---------------------\n";

        try
        {
            PresidentialPardonForm pres("Arthur Dent");
            low.signForm(pres);       
            high.executeForm(pres);
        }
        catch (std::exception &e)
        {
            std::cout << "Presidential error: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Error creating Bureaucrat: " << e.what() << std::endl ;
    }


}


