/******************************************************************
  Write a C++ program for implementation of following algorithms
  a) Knapsack algorithm b) Job sequence with dead line
*******************************************************************/

#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity)
{
  float x[20], tp = 0.0;
  int i, j, u;
  u = capacity;

  // Initialising elements of Array x[] to 0.0
  for (i = 0; i < n; i++)
  {
    x[i] = 0.0;
  }

  for (i = 0; i < n; i++)
  {
    if (weight[i] > u)
    {
      break;
    }
    else
    {
      x[i] = 1.0;
      tp = tp + profit[i];
      u = u - weight[i];
    }
  }

  if (i < n)
  {
    x[i] = u / weight[i];
  }
  tp = tp + (x[i] * profit[i]);
  cout << "\nCumulative benefit is: " << tp;
}

int main()
{
  system("cls");
  float weight[20], profit[20], capacity;
  int num, i, j;
  float ratio[20], temp;

  cout << "\nEnter the number of objects: ";
  cin >> num;
  cout << "\nEnter the total capacity: ";
  cin >> capacity;

  cout << "\nEnter Ratio weight and profit: ";
  for (i = 0; i < num; i++)
  {
    cout << "\nItem " << i + 1 << ": ";
    cout << "\n\tRatio: ";
    cin >> ratio[i];
    cout << "\tWeight: ";
    cin >> weight[i];
    cout << "\tProfit: ";
    cin >> profit[i];
  }

  knapsack(num, weight, profit, capacity);

  return 0;
}