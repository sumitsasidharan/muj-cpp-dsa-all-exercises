/******************************************************************
  Write a C++ program for implementation of 
  Job sequence with dead line
*******************************************************************/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

using namespace std;

struct Job
{
  char id[5];
  int deadline;
  int profit;
};

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y)
{
  if (x < y)
    return x;
  return y;  // else return y
}

int main()
{
  system("cls");
  int i, j, n;
  Job jobs[5];

  cout <<"\nEnter the number of jobs: ";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    cout << "\nEnter the job: ";
    cin >> jobs[i].id;
    cout << "\nEnter the Profit: ";
    cin >> jobs[i].profit;
    cout << "\nEnter deadline: ";
    cin >> jobs[i].deadline;
  }

  Job temp;
  cout << "\nJob(i)\t\tProfit\t Deadline\t Profit/Time\t \n\n";
  cout << "___________________________________________________";
  for (i = 0; i < n; i++)
  {
    cout << "\n\n";
    cout << jobs[i].id << "\t\t" << jobs[i].profit << "\t\t" << jobs[i].deadline << "\t\t" << jobs[i].profit;
  }

  for (i = 1; i < n; i++)
  {
    for (j = 0; j < n-i; j++)
    {
      if (jobs[j+1].profit > jobs[j].profit)
      {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  cout << "\n\nTotal number of jobs: " << n << endl;
  jobSequencingWithDeadline(jobs, n);

  return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n)
{
  int i, j, k, maxprofit;
  int timeslot[MAX];
  int filledTimeSlot = 0;
  int dmax = 0;

  for (i = 0; i < n; i++)
  {
    if (jobs[i].deadline > dmax)
    {
      dmax = jobs[i].deadline;
    }
  }

  cout << "\nTotal time slot: " << dmax;

  // Assigning -1  to array, denoting empty or free timeslot
  for (i = 1; i <= dmax; i++)
  {
    timeslot[i] = -1;
  }
  cout << "\n\nNumber of jobs done: " << dmax;

  for (i = 1; i <= n ; i++)
  {
    k = minValue(dmax, jobs[i-1].deadline);
    while (k >= 1)
    {
      if (timeslot[k] == -1)
      {
        timeslot[k] = i - 1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    if (filledTimeSlot == dmax)
    {
      break;
    }
  }
  // end of for loop

  cout << "\nJobs done: \n";
  for (i = 1; i <=dmax; i++)
  {
    cout << "\tJob: " << jobs[timeslot[i]].id << " at time: " << i << endl;
  }
  maxprofit = 0;

  for (i = 1; i <= dmax; i++)
  {
    maxprofit += jobs[timeslot[i]].profit;
  }
  cout << "\nTotal profit: " << maxprofit;
}