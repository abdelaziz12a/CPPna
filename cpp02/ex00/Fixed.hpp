
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
    private:
        int fixed_point;
        static const int Fraction_B = 8;

    public:
        Fixed();

        //COPY CONSTRACTUR;
        Fixed(const Fixed& other);

        //CPY ASSIGMENT;
        Fixed& operator=(const Fixed& other);

        ~Fixed();
        int getRawBits(void) const;
        void setRawBits( int const raw );
};


#endif