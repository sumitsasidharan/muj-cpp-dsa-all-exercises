/************************************
  Implement Queues using Linked List
*************************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct node {
  int info;
  struct node *next;
};

class Queue {
  private:
    node *rear;
    node *front;

  public:
    Queue(){
      rear = NULL;
      front = NULL;
    }
    void Enqueue();
    void Dequeue();
    void display();

};

void Queue::Enqueue() {
  int data;
  node *temp = new node;
  cout << "Enter the data to be inserted: ";
  cin >> data;
  temp->info = data;
  temp->next = NULL;

  // if front is NULL, Queue is empty
  if (front == NULL) {
    front = temp;
  }
  else {
    rear->next = temp;
  }
  rear = temp; // rear points to the last node
}

void Queue::Dequeue() {
  node *temp = new node;
  if (front == NULL) {
    cout << "Queue is empty\n";
  }
  else {
    temp = front;
    front = front->next;
    cout << "The data deleted from Queue is: " << temp->info;
    delete temp;
  }
}

void Queue::display() {
  node *p = new node;
  p = front;
  if (front == NULL) {
    cout << "Queue is empty\n";
  }
  else {
    cout << "\nContents of Queue: ";
    while(p != NULL) {
      // cout << p->info << "\t";
      printf(" %d ", p->info);
          p = p->next;
    }
  }
}


int main() {
  system("cls");
  Queue q;
  int choice;

  while (1) {
    cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice) {
      case 1: q.Enqueue();
              break;
      case 2: q.Dequeue();
              break;
      case 3: q.display();
              break;
      case 4: exit(0);
      default:
        cout << "\nSorry, your answer is incorrect. Please enter corret choice(1-4): \n";
      
    }
  }

  return 0;
}