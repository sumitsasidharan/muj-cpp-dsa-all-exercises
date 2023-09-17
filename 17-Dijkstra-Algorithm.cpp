/******************************************************************
  Write a C++ program for implementation of Dijkstra’s algorithm
*******************************************************************/

#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

struct node {
  int DistanceValue;
  int status;
  char data;
  int weight;
  struct node *next;
  struct node *adj;
};

class Graph {
  private:
    node *start;

  public:
    Graph() {
      create();
    }
    struct node *p, *q, *k, *l;
    void create();
    int sputil(char Vt);
    char getstart();  // returns start node's data
    // ~Graph();         // Destructor to deallocate memory
};

char Graph::getstart()
{
  return start->data;
}

void Graph::create()
{
  int flag = 0, weight;
  char dat;
  start = NULL;

  cout << "Enter the nodes in the graph(press x to exit): " << endl;
  while(1)
  {
    cin >> dat;
    if (dat == 'x') {
      break;
    }
    p = new node;
    p->data = dat;
    p->status = 0;
    // p->next = NULL;
    // p->adj = NULL;
    p->next = nullptr; // Initialize next to nullptr
    p->adj = nullptr;  // Initialize adj to nullptr

    // first node if flag is 0
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
  // END OF WHILE LOOP

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
      else{
        l->adj = k;
        l = k;
      }
      q = start;
      while (q != NULL) // qhile q reaches end of graph
      {
        if (q->data == dat) {
          k->next = q;
        }
        q = q->next;
      }
    }
    p = p->next;
  }
  p = start;
  k = p->adj;
  while (p != NULL)
  {
    if (k != NULL)
    {
      q = k->next;
      cout << "Enter the weight of  the edge: " << p->data << "---" << q->data << ": ";
      cin >> k->weight;
      k = k->adj;
    }
    else{
      p = p->next;
      k = p->adj;
    }
  }

  return;
}

int Graph::sputil (char Vt)
{
  node *m = NULL;
  int LowDv;  // Lowest Distance Value
  p = start;

  while (p != NULL)
  {
    if (p->data != start->data) {
      p->DistanceValue = 9999;
    }
    else{
      p->DistanceValue = 0;
    }
    p->status = 0;
    p = p->next;
  }
  
  while(1)
  {
    p = start;
    LowDv = 9999;  // highest distance value to start with
    while (p != NULL)
    {
      if (p->DistanceValue <= LowDv && p->status != 1)
      {
        LowDv = p->DistanceValue;
        q = p;
      }
      p = p->next;
    }

    if (q->data == Vt)
    {
      break;
    }
    k = q->adj;
    q->status = 1;

    while (k != NULL)
    {
      m = k->next;
      if ((q->DistanceValue + k->weight) < m->DistanceValue)
      {
        m->DistanceValue = q->DistanceValue + k->weight;
      }
      k = k->adj;
    }
  }

  return q->DistanceValue;
}

int main()
{
  
  char vs, vt;
  int shortest_distance = 0;
  // system("cls");

  Graph graphobj;
  vs = graphobj.getstart();
  cout << "\nEnter the terminal vertex: ";
  cin >> vt;

  shortest_distance = graphobj.sputil(vt);

  cout << "\nThe shortest distance between " << vs << " and " << vt << " is " << shortest_distance;
  

  return 0;
}
