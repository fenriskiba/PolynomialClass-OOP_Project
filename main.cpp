/*Object Oriented Programming HW3
  Grant Carroll
  Based on 801-polynomial-1.pdf*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include "polynomial.hpp"

using namespace std;

int main()
{
    //Create Polynomials A and B
    vector<int> tempArray = {4,3,2,1};
    Polynomial A(tempArray);
    cout << "Polynomial A will be " << A << "\n"
            << "Input coefficients for Polynomial B starting with the most significant coefficient\n"
            << "When done input \"x\"\n";
    
    string userIn;
    vector<int> temp;
    
    cin >> userIn;
    
    while(userIn != "x")
    {
        temp.push_back(atoi(userIn.c_str()));
        cin >> userIn;
    }
    
    reverse(temp.begin(), temp.end());
    
    Polynomial B(temp);
    
    cout << "Polynomial B will be " << B << "\n";
    
    //Demonstrate Getters
    int highestMonomialPower = B.getPowerOfLastMonomial();
    cout << "The most significant monomial in B is "
            << B.getCoefficientAt(highestMonomialPower) 
            << "x^" << highestMonomialPower << "\n";
    
    //Demonstrage Arithmetic
    Polynomial C;
    Polynomial D;
    Polynomial E;
    
    C = A + B;
    D = A - B;
    E = B * 2;
    
    cout << "Polynomial C = A + B = " << C
            << "\nPolynomial D = A - B = " << D
            << "\nPolynomial E = 2 * B = " << E << "\n";
    
    //Demonstrate Comparison
    cout << "A == B: " << (A == B ? "True" : "False")
            << "\nC != E: " << (C != E ? "True" : "False")
            << "\nA == E: " << (A == E ? "True" : "False") << "\n";
    
    return 0;
}
