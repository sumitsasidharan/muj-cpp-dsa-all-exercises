/**************************************
  Convert Infix Expression to Postfix
***************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int top = -1;
// char stack[100] = { NULL };
char stack[100] = {};
void push(const char);
const char pop();
void infix_to_postfix(const char *);

int main()
{
  system("cls");
  // char in_exp[100] = { NULL };
  char in_exp[100] = {};
  cout << "\nEnter the Infix Expression: ";
  cin.getline(in_exp, 80); // reads the input & writes to array in_exp

  infix_to_postfix(in_exp);

  return 0;
}

void push(const char Symbol)
{
  if (top == 99)
  {
    cout << "Stack if full.\n";
  }
  else
  {
    top++;
    stack[top] = Symbol;
  }
}

const char pop()
{
  char Symbol;
  if (top == -1)
  {
    cout << "Stack is empty." << endl;
  }
  else
  {
    Symbol = stack[top];
    // stack[top] = NULL;
    stack[top] = {};
    top--;
  }

  return Symbol;
}

void infix_to_postfix(const char *Infix)
{
  // char in_exp[100] = { NULL };
  // char post_exp[100] = { NULL };
  char in_exp[100] = {};
  char post_exp[100] = {};
  strcpy(in_exp, "(");
  strcat(in_exp, Infix);
  strcat(in_exp, ")");
  // char Symbol[5] = { NULL };
  // char Temp[5] = { NULL };
  char Symbol[5] = {};
  char Temp[5] = {};

  for (int count = 0; count < strlen(in_exp); count++)
  {
    Symbol[0] = in_exp[count];
    if (Symbol[0] == '(')
    {
      push(Symbol[0]);
    }
    else if (Symbol[0] == ')')
    {
      Symbol[0] = pop();
      while (Symbol[0] != '(')
      {
        strcat(post_exp, Symbol);
        Symbol[0] = pop();
      }
    }
    else if (Symbol[0] == '*' || Symbol[0] == '/' || Symbol[0] == '+' || Symbol[0] == '-')
    {
      if (Symbol[0] == '*' || Symbol[0] == '/')
      {
        Temp[0] = pop();
        while (Temp[0] == '*' || Temp[0] == '/')
        {
          strcat(post_exp, Temp);
          Temp[0] = pop();
        }
        push(Temp[0]);
      }
      else if (Symbol[0] == '+' || Symbol[0] == '-')
      {
        Temp[0] = pop();
        while (Temp[0] != '(')
        {
          strcat(post_exp, Temp);
          Temp[0] = pop();
        }
        push(Temp[0]);
      }
      push(Symbol[0]);
    }
    // if character is not operator, it's an operand
    else
    {
      strcat(post_exp, Symbol);
    }
  }
  cout << "\n\nPostfix Expression: " << post_exp << endl;
}