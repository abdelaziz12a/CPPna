#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}


Base* Base::generate(void)
{
    int rand = rand() % 3;

    if (rand == 0)
    {
        return new A();
    }
    if (rand == 1)
    {

    }
    else
    {

    }


}
void Base::identify(Base* p)
{

}
void Base::identify(Base& p)
{

}