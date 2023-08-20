/********************************************************************************
    * Elementary Algorithms
    Write a C++ program for implementation of following elementary algorithms.
    b) Factorial of given number using recursion
    
*********************************************************************************/

#include <iostream>
#include <conio.h>

using namespace std;

int factorial(int fac);

int main()
{
  system("cls");
  int fac;
  cout <<"nEnter a positive integer: ";
  cin >> fac;

  cout << "\nFactorial of " << fac << " = " << factorial(fac);
  

  return 0;
}

int factorial(int fac)
{
  if (fac == 1)
    return 1;
  else
    fac = fac * factorial(fac - 1);

  return fac;
}