#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *AAnimal[4];

    for (int i = 0 ; i < 4 ;i++)
    {
        if (i < 2)
        {
            std::cout << "Cat : " << i + 1 << std::endl;
            AAnimal[i] = new Cat();
        }
        else
        {
            std::cout << "Dog : " << i -1 << std::endl;
            AAnimal[i] = new Dog();
        }
    }

    for (int i = 0 ; i < 4 ;i++)
        delete AAnimal[i] ;
    return 0;
}