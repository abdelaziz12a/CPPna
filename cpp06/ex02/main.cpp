#include "Base.hpp"


int main()
{
    srand(std::time(NULL));

    Base bs;

    Base *ix = new Base;

    Base *o = bs.generate();

    bs.identify(o);
    bs.identify(*o);

}