/*Object Oriented Programming HW3
  Grant Carroll
  Based on 801-polynomial-1.pdf*/

#include "polynomial.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Getters
int Polynomial::getCoefficientAt(int power) const
{
    return coefficients.at(power);
}

int Polynomial::getPowerOfLastMonomial() const
{
    return coefficients.size() - 1;
}

//Addition Operator
    //Will add the coefficients of the polynomials together and return the resulting polynomial
    //ex. (ax^n + bx^n-1 + ... + cx^1 + d) + (ex^n + fx^n-1 + ... + gx^1 + h)
    //      = (a+e)x^n + (b+f)x^n-1 + ... + (c+g)x^1 + (d+h)
Polynomial Polynomial::operator+(const Polynomial& a)
{
    int thisSize = coefficients.size();
    int thatSize = a.coefficients.size();
    
    int lower = min(thisSize, thatSize);
    int upper = max(thisSize, thatSize);
    
    bool thisIsGreater = (upper == thisSize);
    
    vector<int> coefficientArray(upper,0);

    //Loop through area both are in
    for(int i = 0; i < lower; i++)
    {
        coefficientArray.at(i) = coefficients.at(i) + a.coefficients.at(i);
    }
    
    //Loop through and copy the rest
    for(int i = lower; i < upper; i++)
    {
        if(thisIsGreater)
        {
            coefficientArray.at(i) = coefficients.at(i);
        }
        else
        {
            coefficientArray.at(i) = a.coefficients.at(i);
        }
    }
    
    //Test for 0 coefficient at the top
    while(coefficientArray.back() == 0)
    {
        coefficientArray.pop_back();
    }
    
    Polynomial temp(coefficientArray);
    return temp;
}

//Subtraction Operator
    //Will subtract the coefficients of the polynomials and return the resulting polynomial
    //ex. (ax^n + bx^n-1 + ... + cx^1 + d) - (ex^n + fx^n-1 + ... + gx^1 + h)
    //      = (a-e)x^n + (b-f)x^n-1 + ... + (c-g)x^1 + (d-h)
Polynomial Polynomial::operator-(const Polynomial& a)
{
    int thisSize = coefficients.size();
    int thatSize = a.coefficients.size();
    
    int lower = min(thisSize, thatSize);
    int upper = max(thisSize, thatSize);
    
    bool thisIsGreater = (upper == thisSize);
    
    vector<int> coefficientArray(upper,0);

    //Loop through area both are in
    for(int i = 0; i < lower; i++)
    {
        coefficientArray.at(i) = coefficients.at(i) - a.coefficients.at(i);
    }
    
    //Loop through and copy the rest
    for(int i = lower; i < upper; i++)
    {
        if(thisIsGreater)
        {
            coefficientArray.at(i) = coefficients.at(i);
        }
        else
        {
            coefficientArray.at(i) = -1 * a.coefficients.at(i);
        }
    }
    
    //Test for 0 coefficient at the top
    while(coefficientArray.back() == 0)
    {
        coefficientArray.pop_back();
    }
    
    Polynomial temp(coefficientArray);
    return temp;
}

//Multiplication Operator
    //Not in the original design but simple enough to implement
    //Multiplies each coefficient by the given int
    //ex. 5 * (ax^n + bx^n-1 + ... + cx^1 + d) = 5ax^n + 5bx^n-1 + ... + 5cx^1 + 5d
Polynomial Polynomial::operator*(int a)
{
    int upper = coefficients.size();
    vector<int> coefficientArray(upper,0);
    
    for(int i = 0; i < upper; i++)
    {
        coefficientArray.at(i) = coefficients.at(i) * a;
    }
    
    //Test for 0 coefficient at the top
    while(coefficientArray.back() == 0)
    {
        coefficientArray.pop_back();
    }
    
    Polynomial temp(coefficientArray);
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
bool operator==(const Polynomial& a, const Polynomial& b)
{
    if(a.getPowerOfLastMonomial() != b.getPowerOfLastMonomial())
    {
        return false;
    }
    
    for(int i = 0; i < a.getPowerOfLastMonomial() + 1; i++)
    {
        if(a.getCoefficientAt(i) != b.getCoefficientAt(i))
        {
            return false;
        }
    }
    
    return true;
}

bool operator!=(const Polynomial& a, const Polynomial& b)
{
    return !(a == b);
}

//Stream Operator
ostream& operator<<(ostream& os, const Polynomial& poly)
{
    int upper = poly.getPowerOfLastMonomial();
    string temp = "";
    
    for(int i = upper; i >=0; i--)
    {
        if(poly.getCoefficientAt(i) != 0)
        {
            if(temp != "" && poly.getCoefficientAt(i) > 0)
            {
                temp += " + ";
            }
            else if(temp != "" && poly.getCoefficientAt(i) < 0)
            {
                temp += " - ";
            }
            
            temp += abs(poly.getCoefficientAt(i));
            
            if(i > 0)
            {
                temp += "x^" + i;
            }
        }
    }
    
    os << temp;
    return os;
}

