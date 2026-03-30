
#include "PhoneBook.hpp"

void welcome()
{
    std::cout << " [------MY PHONEBOOK------]" << std::endl;
    std::cout << " |to add type : ADD       |" << std::endl;
    std::cout << " |to search type : SEARCH |" << std::endl;
    std::cout << " |to exit type : EXIT     |" << std::endl;
    std::cout << " [------------------------]" << std::endl;
}

int main()
{
    PhoneBook f;
    std::string input;
    while(1)
    {
        welcome();
        if (!std::getline(std::cin, input)) break;
        if (input == "ADD") f.addContact();
        else if (input == "SEARCH") f.searchContact();
        else if (input == "EXIT") break;
        else std::cout << " *Unknown command\n";
    }
} 