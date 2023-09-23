/*
  Write a C++ program for implementation of stack Using 
  a) Array ONLY b) Linked List (not provided in MUJ Student portal)
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
using namespace std;

class stk {
  int maxstk, top, n, i, a[MAX];
  char ch;
  public:
    stk() {
      top = -1;
    }
    void push();
    void pop();
    void  display();
};

void stk::push() {
  if (top >= MAX-1) {
    cout << "Stack Overflow" << endl;
  }
  else {
    top++;
    cout << "Enter the elements to be pushed.";
    cin >> n;
    a[top] = n;
  }
}

void stk::pop() {
  if (top < 0) {
    cout << "Stack underflow." << endl;
  }
  else {
    n = a[top];
    top--;
  }
}

void  stk::display() {
  cout << "After operation, the elements of Stack: ";
  for (i = 0; i <= top; i++) {
    cout << a[i] << "\t";
  }
}


int main() {
  system("cls");

  stk s;
  int ch;
  while(1) {
    cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    switch(ch) {
      case 1: s.push();
              break;
      case 2: s.pop();
              break;
      case 3: s.display();
              break;
      case 4: exit(0);
      default:
        cout << "Sorry your answer is incorrect. Please enter correct choice. (1-4)";
    }
  }


  return 0;
}