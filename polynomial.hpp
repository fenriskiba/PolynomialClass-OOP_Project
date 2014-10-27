#ifndef POLYNOMIAL_HPP
#define	POLYNOMIAL_HPP

#include <iostream>
#include <vector>

class Polynomial
{
    private:
        std::vector<int> coefficients;
    
    public:
        Polynomial(int coefficientArray[], int size) : coefficients(&coefficientArray[0], &coefficientArray[0]+size){}
        Polynomial(std::vector<int> coefficientVector) : coefficients(coefficientVector){}
        Polynomial(const Polynomial& a) : coefficients(a.coefficients){}
        
        int getCoefficientAt(int power) const;
        int operator[](int power) const;
        
        Polynomial operator+(const Polynomial& a);
        Polynomial operator-(const Polynomial& a);
        void operator=(const Polynomial& a);
        void operator+=(const Polynomial& a);
        void operator-=(const Polynomial& a);
};

bool operator==(const Polynomial& a, const Polynomial& b);
bool operator!=(const Polynomial& a, const Polynomial& b);

std::ostream& operator<<(std::ostream& os, const Polynomial& t);

#endif
