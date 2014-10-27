#ifndef POLYNOMIAL_HPP
#define	POLYNOMIAL_HPP

#include <iostream>
#include <vector>

class Polynomial
{
    private:
        std::vector<int> coefficients;
    
    public:
        //Constructors
            //Can be intitialized with an array or vector of integers representing the coefficients
            //Can also be initialized using a copy constructor and another Polynomial
        Polynomial(int coefficientArray[], int size) : coefficients(&coefficientArray[0], &coefficientArray[0]+size){}
        Polynomial(std::vector<int> coefficientVector) : coefficients(coefficientVector){}
        Polynomial(const Polynomial& a) : coefficients(a.coefficients){}
        
        //Getter
            //Takes in the degree and returns the coefficient at that degree
            //Vector bounds errors past the bounds of the current polynomial
        int getCoefficientAt(int power) const;
        
        //Arithmetic and Assignment Operators
            //Based on algebraic definitions of operations with polynomials
            //More detailed explanations are provided with the implementation of each operator
        Polynomial operator+(const Polynomial& a);
        Polynomial operator-(const Polynomial& a);
        Polynomial operator*(int a);
        void operator=(const Polynomial& a);
        void operator+=(const Polynomial& a);
        void operator-=(const Polynomial& a);
        void operator*=(int a);
};

//Comparison Operators
    //Equality will be defined as having the same maximum degree and all coefficients being equal
bool operator==(const Polynomial& a, const Polynomial& b);
bool operator!=(const Polynomial& a, const Polynomial& b);

//Stream Operator
    //Outputs in the format: ax^n + bx^n-1 + ... + cx^1 + d
std::ostream& operator<<(std::ostream& os, const Polynomial& t);

#endif
