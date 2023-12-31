/**************************************
  Graphs Part B
  Write a C++ Program for implementation of graph using following
  Traversals on it b) DFS (Depth-first Search)

  Input:
  Enter the nodes in the graph(press x to exit): ABCDEFX
  Enter the links to A (x to exit): BCDx
  Enter the links to B (x to exit): EFx
  Enter the links to C (x to exit): Fx
  Enter the links to D (x to exit): x
  Enter the links to E (x to exit): x
  Enter the links to F (x to exit): x

  DFS for graph is: A B E F C D
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

void create()
{
  int flag = 0;
  char dat;
  start = NULL;
  cout << "Enter the nodes in the graph (press x to exit): " << endl;
  while (1)
  {
    cin >> dat;
    if (dat == 'x') {
      break;
    }
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
    else {
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
      if (dat == 'x') {
        break;
      }
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
      while(q != NULL)
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

void  dfsUtil(node *startnode)
{
  int sp = -1; // Stack Pointer
  node *stack[100];
  p = startnode;
  cout << p->data;
  p->status = 1;
  k = p->adj;
  while(1)
  {
    if (k != NULL)
    {
      sp++;
      stack[sp] = k;
      q = k->next;
      if (q->status == 0)
      {
        cout << " ";
        cout << q->data;
        q->status = 1;
        k = q->adj;
      }
      else
      {
        k = k->adj;
      }
    }
    else
    {
      if (sp >= 0)
      {
        k = stack[sp];
        sp--;
        k = k->adj;
      }
      else {
        break;
      }

    }
  }
}

void dfs()
{
  p = start;
  while (p != NULL)
  {
    p->status = 0;
    p = p->next;
  }
  p = start;
  while(p != NULL)
  {
    if (p->status == 0)
      dfsUtil(p);
    else
      p = p->next;
  }
}


int main()
{
  system("cls");
  create();
  cout << "\n\nDFS for the Graph is: ";
  dfs();

  return 0;
}