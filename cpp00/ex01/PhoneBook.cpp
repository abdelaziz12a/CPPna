
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : cont_contact(0), next_index(0){}

bool isOnlyLetters(std::string s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isalpha(s[i]))
            return false;
    }
    return true;
}

bool isOnlyDigits(std::string s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool isValidDs(std::string s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isprint(s[i]))
            return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    std::string fn, ln, nk, pn, ds;

    std::cout << "First Name: ";
    if (!std::getline(std::cin, fn))
        exit(0);
    if (!isOnlyLetters(fn))
    {
        std::cout << "Error: In valide First Name!\n";
        return;
    }

    std::cout << "Last Name: ";
    if (!std::getline(std::cin, ln))
        exit(0);
    if (!isOnlyLetters(ln))
    {
        std::cout << "Error: In valide Last Name or empty!\n";
        return;
    }

    std::cout << "Nickname: ";
    if (!std::getline(std::cin, nk))
        exit(0);
    if (!isOnlyLetters(nk))
    {
        std::cout << "Error: In valide Nickname or empty!\n";
        return;
    }

    std::cout << "Phone Number: ";
    if (!std::getline(std::cin, pn))
        exit(0);
    if (!isOnlyDigits(pn))
    {
        std::cout << "Error: In valide Phone Number or empty!\n";
        return;
    }

    std::cout << "Darkest Secret: ";
    if (!std::getline(std::cin, ds))
        exit(0);
    if (!isValidDs(ds))
    {
        std::cout << "Error: In valide Darkest Secret or empty!\n";
        return;
    }

    contacts[next_index].setContact(fn, ln, nk, pn, ds);

    if (cont_contact < 8)
        cont_contact++;

    next_index = (next_index + 1) % 8;

    std::cout << "Contact added successfully!\n";
}

void printField(const std::string& str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::right << str;
}

void PhoneBook::searchContact()
{
    if (cont_contact == 0)
    {
        std::cout << " PhoneBook is empty\n";
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname|\n";

    for (int i = 0; i < cont_contact; i++)
        {
        std::cout << std::setw(10) << i << "|";

        printField(contacts[i].getFirstName());
        std::cout << "|";

        printField(contacts[i].getLastName());
        std::cout << "|";

        printField(contacts[i].getNickname());
        std::cout << "|\n";
    }

    std::string input;
    int index;

    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input))
        return;

    if (input.length() != 1 || input[0] < '0' || input[0] >= '0' + cont_contact)
    {
        std::cout << "  Invalid index\n";
        return;
    }

    index = input[0] - '0';

    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}