/********************************************************************************
    * Elementary Algorithms
    Write a C++ program for implementation of following elementary algorithms.
    a) Compute GCD (greatest common divisor) of two given positive integers.
    b) Factorial of given number using recursion
    c) Procedure to calculate sum of squares of two integer numbers
    d) Program to find the maximum and minimum in set of n integer elements

*********************************************************************************/

#include <iostream>
#include <conio.h>

using namespace std;

int gcd(int, int);

int main()
{
  system("cls");
  int x, y;

  cout << "\nEnter two positive integers: ";
  cin >> x >> y;
  cout << "\nGCD of two numbers (" << x << "," << y << ")= " << gcd(x,y) << endl;


  return 0;
}


int gcd(int m, int n)
{
  int r;
  while (n != 0)
  {
    r = m%n;
    m = n;
    n = r;
  }

  return m;
}