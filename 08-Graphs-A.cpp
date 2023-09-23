/**************************************
  Write a C++ Program for implementation of graph using following Traversals on it
  a) BFS (Breadth-first Search)

  Input:
  Enter the nodes in the graph(press x to exit):
  a b c d e f x
  Enter the links to a (x to exit): b c d x
  Enter the links to b (x to exit): e f x
  Enter the links to c (x to exit): f x
  Enter the links to d (x to exit): x
  Enter the links to e (x to exit): x
  Enter the links to f (x to exit): x

  BFS for graph is: abcdef
***************************************/

#include <iostream>
#include <conio.h>
#include <ctype.h>
using namespace std;

struct node {
  int status;
  char data;
  struct node *next;
  struct node *adj;
};

struct node *p, *q, *start, *k, *l;

void create() {
  int flag = 0;
  char dat;
  start = NULL;
  
  cout << "Enter the nodes in the graph (press x to exit): " << endl;
  while(1)
  {
    cin >> dat;
    if (dat == 'x') break;

    p = new node;
    p->data = dat;
    p->status = 0;
    p->next = NULL;
    p->adj = NULL;

    if (flag == 0)
    {
      start = p;
      q = p;
      flag++;
    }
    else 
    {
      q->next = p;
      q = p;
    }
  }

  p = start;
  while (p != NULL)
  {
    cout << "Enter the links to " << p->data << "(x to exit): ";
    flag = 0;
    while(1)
    {
      cin >> dat;
      if (dat == 'x') break;

      k = new node;
      k->adj = NULL;
      if (flag == 0)
      {
        p->adj = k;
        l = k;
        flag++;
      }
      else
      {
        l->adj = k;
        l = k;
      }
      q = start;
      while (q != NULL)
      {
        if (q->data == dat) {
          k->next = q;
        }
        q = q->next;
      }
    }
    p = p->next;
  }
  return;
}

void bfs()
{
  int i = 1, j = 0;
  char qu[20];
  p = start;
  while (p != NULL)
  {
    p->status = 0;
    p = p->next;
  }
  p = start;
  qu[0] = p->data;
  cout << qu[0];
  p->status = 1;

  while(1)
  {
    if (qu[j] == 0){
      break;
    } 

    p = start;
    while (p != NULL)
    {
      if (p->data == qu[j]) {
        break;
      }
      p = p->next;
    }
    k = p->adj;
    while (k != NULL)
    {
      q = k->next;
      if (q->status == 0)
      {
        qu[i] = q->data;
        cout << qu[i];
        q->status = 1;
        qu[i+1] = 0;
        i++;
      }
      k = k->adj;
    }
    j++;
  }
}


int main() {
  system("cls");
  create();

  cout << "BFS for the Graph is: ";
  bfs();

  return 0;
}