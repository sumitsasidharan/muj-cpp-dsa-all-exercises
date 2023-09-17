/*
  Issue with Deletion. No message displaying when Queue is empty.
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Queue {
  public:
  int q[5], front, rear, x, result;
  void Enqueue();
  void Dequeue();
  void display();
  Queue() {
    front = 0;
    rear = 0;
  }
};

void Queue::Enqueue() {
  if (rear > 5) {
    cout << "\nQueue overflow.\n";
  }
  else {
    cout << "\nEnter the number to be inserted: ";
    cin >> x;
    rear++;
    q[rear] = x;
    cout << "\nNumber inserted in the Queue: " << q[rear];
  }
}

void Queue::Dequeue() {
  if(rear == 0) {
    cout << "\nQueue underflow!\n";
  }
  else {
    if (front == rear) {
      front = 0;
      rear = 0;
    }
    else {
      front++;
    }
  }
  result = q[front];
}

void Queue::display() {
  if (rear == 0) {
    cout << "\nQueue underflow!\n";
  }
  else {
    cout << "\nContents of Queue: ";
    for (int i = front + 1; i <= rear; i++) {
      cout << q[i] << "\t";
    }
    cout << endl;
  }
}

int main() {
  int c;
  Queue qu;
  system("cls");

  do {
    cout << "\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> c;
    switch(c) {
      case 1: qu.Enqueue();
              break;
      case 2: qu.Dequeue();
              break;
      case 3: qu.display();
              break;
      case 4: exit(0);
      default: 
        cout << "\nSorry your answer is incorrect. Please enter correct choice (1-4)\n";
    }
  } while(c != 4);

  cout << "Value of c is: " << c << endl;

  getch();

  return 0;
}