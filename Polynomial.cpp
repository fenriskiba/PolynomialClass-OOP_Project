#include "Polynomial.hpp"
#include <iostream>

using namespace std;

//Constructors
Polynomial::Polynomial(){}
Polynomial::Polynomial(int[] coefficientArray, int size){}
Polynomial::Polynomial(vector<int> coefficientVector){}
Polynomial::Polynomial(const Polynomial& a){}

//Getters
int getCoefficientAt(int power) const{}
int operator[](int power) const{}

//Arithmetic Operators
Polynomial Polynomial::operator+(const Polynomial& a){}
Polynomial Polynomial::operator-(const Polynomial& a){}
void Polynomial::operator=(const Polynomial& a){}
void Polynomial::operator+=(const Polynomial& a){}
void Polynomial::operator-=(const Polynomial& a){}

//Comparison Operators
bool operator==(const Polynomial& a, const Polynomial& b){}
bool operator!=(const Polynomial& a, const Polynomial& b){}

//Stream Operator
ostream& operator<<(ostream& os, const Polynomial& t){}
