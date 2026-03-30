#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
    private:
        int F_Valu;
        static const int Fraction_B = 8;

    public:
        Fixed();
        Fixed(const int& i);
        Fixed(const float& i);
        //COPY CONSTRACTUR;
        Fixed(const Fixed& other);

        //CPY ASSIGMENT;
        Fixed& operator=(const Fixed& other);

        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits(void) const;
        void setRawBits( int const raw );
};


#endif