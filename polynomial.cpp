/*Object Oriented Programming HW3
  Grant Carroll
  Based on 801-polynomial-1.pdf*/

#include "polynomial.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Getter
int Polynomial::getCoefficientAt(int power) const
{
    return coefficients.at(power);
}

//Addition Operator
    //Will add the coefficients of the polynomials together and return the resulting polynomial
    //ex. (ax^n + bx^n-1 + ... + cx^1 + d) + (ex^n + fx^n-1 + ... + gx^1 + h)
    //      = (a+e)x^n + (b+f)x^n-1 + ... + (c+g)x^1 + (d+h)
Polynomial Polynomial::operator+(const Polynomial& a)
{
    int lower = min(coefficients.size(), a.coefficients.size());
    int upper = max(coefficients.size(), a.coefficients.size());
    
    bool thisIsGreater = (upper == coefficients.size());
    
    int *coefficientArray = new int[upper];

    //Loop through area both are in
    for(int i = 0; i < lower; i++)
    {
        coefficientArray[i] = coefficients.at(i) + a.coefficients.at(i);
    }
    
    //Loop through and copy the rest
    for(int i = lower; i < upper; i++)
    {
        if(thisIsGreater)
        {
            coefficientArray[i] = coefficients.at(i);
        }
        else
        {
            coefficientArray[i] = a.coefficients.at(i);
        }
    }
    
    Polynomial temp(coefficientArray, upper);
    return temp;
}

//Subtraction Operator
    //Will subtract the coefficients of the polynomials and return the resulting polynomial
    //ex. (ax^n + bx^n-1 + ... + cx^1 + d) - (ex^n + fx^n-1 + ... + gx^1 + h)
    //      = (a-e)x^n + (b-f)x^n-1 + ... + (c-g)x^1 + (d-h)
Polynomial Polynomial::operator-(const Polynomial& a)
{
    int lower = min(coefficients.size(), a.coefficients.size());
    int upper = max(coefficients.size(), a.coefficients.size());
    
    bool thisIsGreater = (upper == coefficients.size());
    
    int *coefficientArray = new int[upper];

    //Loop through area both are in
    for(int i = 0; i < lower; i++)
    {
        coefficientArray[i] = coefficients.at(i) - a.coefficients.at(i);
    }
    
    //Loop through and copy the rest
    for(int i = lower; i < upper; i++)
    {
        if(thisIsGreater)
        {
            coefficientArray[i] = coefficients.at(i);
        }
        else
        {
            coefficientArray[i] = -1 * a.coefficients.at(i);
        }
    }
    
    Polynomial temp(coefficientArray, upper);
    return temp;
}

//Multiplication Operator
    //Not in the original design but simple enough to implement
    //Multiplies each coefficient by the given int
    //ex. 5 * (ax^n + bx^n-1 + ... + cx^1 + d) = 5ax^n + 5bx^n-1 + ... + 5cx^1 + 5d
Polynomial Polynomial::operator*(int a)
{
    Polynomial temp(coefficients);
    
    for(int i = 0; i < coefficients.size(); i++)
    {
        temp.coefficients.at(i) *= a;
    }
    
    return temp;
}

//Equals Assignment Operator
    //Clears the current coefficients and copies coefficients from "a"
void Polynomial::operator=(const Polynomial& a)
{
    coefficients.clear();
    coefficients = a.coefficients;
}

//Addition, Subtraction, and Multiplication Assignment Operators
    //Adds, Subtracts, or Multiplies the current and given Polynomial and sets the current one to the result
void Polynomial::operator+=(const Polynomial& a)
{
    Polynomial temp = *this + a;
    *this = temp;
}

void Polynomial::operator-=(const Polynomial& a)
{
    Polynomial temp = *this - a;
    *this = temp;
}

void Polynomial::operator*=(int a)
{
    Polynomial temp = *this * a;
    *this = temp;
}

//Comparison Operators
bool operator==(const Polynomial& a, const Polynomial& b){}
bool operator!=(const Polynomial& a, const Polynomial& b){}

//Stream Operator
ostream& operator<<(ostream& os, const Polynomial& t){}
