#include "polynomial.hpp"
#include <iostream>
#include <vector>

using namespace std;

//Getters
int Polynomial::getCoefficientAt(int power) const{}
int Polynomial::operator[](int power) const{}

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
