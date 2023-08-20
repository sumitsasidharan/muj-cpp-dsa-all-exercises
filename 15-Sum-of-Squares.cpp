/********************************************************************************
    * Elementary Algorithms
    Write a C++ program for implementation of following elementary algorithms.
    c) Procedure to calculate sum of squares of two integer numbers
    
*********************************************************************************/

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main()
{
  system("cls");
  int a, b, s;

  cout << "\nProgram to find sum of squares of two integers.";
  cout << "\nEnter the two integers: ";
  cin >> a >> b;

  s = pow(a, 2) + pow(b, 2);

  cout << "\nSumt of squares of the two integer numbers is: " << s;

  return 0;
}
