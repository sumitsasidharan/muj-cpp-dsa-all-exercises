/**************************************
  Searching Methods:
  b) Binary Searching.
***************************************/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
  system("cls");
  int n, i, search, first, last, middle, arr[100];
  
  cout <<"\nEnter the array size: ";
  cin >> n;

  cout << "\nEnter the array elements: ";
  for (i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "\nEnter the number to be searched: ";
  cin >> search;

  // Initialising array positions to first, last and middle;
  first = 0;
  last = n - 1;
  middle = (first + last) / 2;

  while (first <= last)
  {
    // if Search item is greater than middle array item
    if (arr[middle] < search)
    {
      first = middle + 1;
    }
    else if (arr[middle] == search)
    {
      cout << "Key element is found at location: " << middle + 1 << endl;
      break;  // success, terminate loop
    }
    else{
      last = middle - 1;
    }

    // New middle variable, since has not been found
    middle = (first + last) / 2;
  }

  if (first > last)
  {
    cout << "\nKey element is not found!";
  }


  return 0;
}