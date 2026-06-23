#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}


AForm *createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string _name, std::string _target)
{
    std::string name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*creator[3])(std::string) = { &createShrubbery, &createRobotomy, &createPardon};

    for (int i = 0; i < 3 ; i++)
    {
        if (name[i] == _name)
        {
            std::cout << "Intern creates " << name[i] << std::endl;
            return (creator[i](_target));
        }
    }
    std::cout << "Error: form not found" << std::endl;
    return NULL;

}