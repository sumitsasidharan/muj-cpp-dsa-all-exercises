/********************************************************************************
    * Elementary Algorithms
    Write a C++ program for implementation of following elementary algorithms.
    d) Program to find the maximum and minimum in set of n integer elements

*********************************************************************************/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  system("cls");
  int n, i , min = 0, max = 0;
  int Arr[100];

  cout << "\nProgram to find the maximum and minimum in a set of n integer elements.\n";
  cout << "\nEnter the value of n: ";
  cin >> n;
  
  cout << "\nEnter " << n << " values: ";
  for (i = 0; i < n; i++)
  {
    cin >> Arr[i];
  }

  // Important: Initialise 'min & max' to first element of the Array Arr[0]
  min = Arr[0];
  max = Arr[0];

  for (i = 1; i < n; i++)
  {
    if (Arr[i] < min) {
      min = Arr[i];
    }

    if (Arr[i] > max) {
      max = Arr[i];
    }
  }

  cout << "\nMaximum value is: " << max;
  cout << "\n\nMinimum value is: " << min;

  return 0;
}
