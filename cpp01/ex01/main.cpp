
#include "Zombie.hpp"

int main()
{
    int N = 5;
    
    Zombie *z =  zombieHorde(N, "gon");
    if (!z)
    {
        std::cout << "error: memory allocation" << std::endl;
        return 1;
    }
    for(int i = 0; i < N;i++)
    {z[i].announce();}
    delete[]z;
}