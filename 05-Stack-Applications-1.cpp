/************************************
  Applications of Stacks 1: Evaluating Postfix Expression
  4. a) Write a C++ Program for Evaluation of postfix expression

  Program Input:
  Enter the postfix expression to be evaluated: 12*3+
  Result is: 5
*************************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
const int MAX = 50;
using namespace std;

class postfix {
  private:
    int stack[MAX];
    int top, m;
    char *s;

  public:
    postfix();
    void setexpression(char *str);
    void push(int item);
    int pop();
    void calculate();
    void show();
};

// below func is executed whenever a new object of this class is created
postfix::postfix() {
  top = -1;  // -1 signifies that stack is empty
}

void postfix::setexpression(char *str) {
  s = str;
}

void postfix::push(int item) {
  if (top == MAX-1) {
    cout << "Stack is full";
  }
  else {
    top++;
    stack[top] = item;
  }
}

int postfix::pop() {
  if (top == -1) {
    cout << "Stack is empty" << endl;
    // return NULL;
    
  }
  else {
    int data = stack[top];
    top--;
    return data;
  }
}

void postfix::calculate() {
  int n1,n2,n3;

  while (*s) {
    if (*s == ' ' || *s == '\t') {
      s++;
      continue;
    }
    if (isdigit(*s)) {
      m = *s - '0';
      push(m);
    }
    else {
      n1 = pop();
      n2 = pop();
      switch (*s) {
        case '+': n3 = n2 + n1;
                  break;
        case '-': n3 = n2 - n1;
                  break;
        case '*': n3 = n2 * n1;
                  break;
        case '/': n3 = n2 / n1;
                  break;
        default: 
                  cout << "Unknown operator";
                  exit(1);
      }
      push(n3);
    }
    s++;
  }
}

void postfix::show() {
  m = pop();
  cout << "Result is: " << m;
}

int main() {
  char expr[MAX];
  system("cls");
  cout << "\nEnter the postfix expression to be evaluated: ";
  cin.getline(expr, MAX); // get input expression and assign to to array expr

  postfix q;
  q.setexpression(expr);
  q.calculate();
  q.show();

  // getch();

  return 0;
}