/**************************************
  Searching Methods
  Write a C++ Program for searching integer number using following methods
  a) Sequential (Linear) Searching 

  Input:
  Enter the array size: 7
  Enter the array elements: 2 5 3 6 8 5 4
  Enter the number to be searched: 8
  Element found at position: 5
***************************************/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
  system("cls");
  int i, num, n, c=0, pos, arr[10];

  cout << "\nEnter the Array size: ";
  cin >> n;

  cout << "\nEnter the array elements: ";
  for (i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "\nEnter the number to be searched: ";
  cin >> num;

  for (i = 0; i < n; i++) {
    if (arr[i] == num)
    {
      c = 1;
      pos = i + 1;
      break;
    }
  }

  if (c == 0)
  {
    cout << "Number not found!";
  }
  else{
    cout << "Element found at position: " << pos;
  }

  return 0;
}