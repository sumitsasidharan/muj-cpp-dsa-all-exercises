/**************************************
  Sorting Methods
  Write a C++ Program for sorting integer numbers using following methods:
  a) Bubble sort b) Selection sort
***************************************/

#include <iostream>
#include <conio.h>

using namespace std;

class Mergesort
{
public:
  int no_of_elements;
  int elements[10];
  void getarray();
  void partition(int[], int, int);
  void sortit(int[], int, int, int);
  void display();
};

void Mergesort::getarray()
{
  cout << "\nEnter the array size: ";
  cin >> no_of_elements;
  cout << "\nEnter the array elements to sort: ";
  for (int i = 0; i < no_of_elements; i++)
  {
    cin >> elements[i];
  }

}

void Mergesort::partition(int elements[], int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    partition(elements, low, mid);
    partition(elements, mid + 1, high);
    sortit(elements, low, mid, high);
  }
}

void Mergesort::sortit(int elements[], int low, int mid, int high)
{
  int i, j, k, l, b[20];
  l = low;
  i = low;
  j = mid + 1;
  while ((l <= mid) && (j <= high))
  {
    if (elements[l] <= elements[j])
    {
      b[i] = elements[l];
      l++;
    }
    else
    {
      b[i] = elements[j];
      j++;
    }
    i++;
  }

  if (l > mid)
  {
    for (k = j; k <= high; k++)
    {
      b[i] = elements[k];
      i++;
    }
  }
  else
  {
    for (k = l; k <= mid; k++)
    {
      b[i] = elements[k];
      i++;
    }
  }

  for (k = low; k <= high; k++)
  {
    elements[k] = b[k];
  }
}

void Mergesort::display()
{
  cout << "\nThe sorted elements: ";
  for (int i = 0; i < no_of_elements; i++)
  {
    cout << elements[i] << " ";
  }
}

int main()
{
  system("cls");
  Mergesort MS;
  MS.getarray();
  MS.partition(MS.elements, 0, MS.no_of_elements);
  MS.display();

  return 0;
}