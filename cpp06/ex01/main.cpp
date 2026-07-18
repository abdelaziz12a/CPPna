#include "Serializer.hpp"


int main ()
{
    Data *p1 = new Data;
    p1->Login = "aaboudra";
    p1->MdPasse = 123;



    std::cout << "data " << p1 << std::endl;

    uintptr_t p2 = 0;
    
    std::cout << "before " << p2 << std::endl;

    p2 = Serializer::serialize(p1);

    std::cout << "after " << p2 << std::endl;
    std::cout << "in hexa "<< std::hex << p2 << std::endl;


    Data *p3 = Serializer::deserialize(p2);

    std::cout << "data " << p3 << std::endl;

    p3 == p1 ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl ;

    delete p1;

}