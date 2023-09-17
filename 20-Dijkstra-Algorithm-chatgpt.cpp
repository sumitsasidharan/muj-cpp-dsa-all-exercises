#include <iostream>
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
  ~Graph(); // Destructor to deallocate memory
};

// Destructor to deallocate dynamically allocated memory
Graph::~Graph() {
  p = start;
  while (p != nullptr) {
    k = p->adj;
    while (k != nullptr) {
      l = k;
      k = k->adj;
      delete l; // Deallocate edge nodes
    }
    l = p;
    p = p->next;
    delete l; // Deallocate graph nodes
  }
}

char Graph::getstart() {
  return start->data;
}

void Graph::create() {
  int flag = 0, weight;
  char dat;
  start = nullptr;

  cout << "Enter the nodes in the graph (press x to exit): " << endl;
  while (1) {
    cin >> dat;
    if (dat == 'x') {
      break;
    }
    p = new node;
    p->data = dat;
    p->status = 0;
    p->next = nullptr; // Initialize next to nullptr
    p->adj = nullptr; // Initialize adj to nullptr

    // first node if flag is 0
    if (flag == 0) {
      start = p;
      q = p;
      flag++;
    } else {
      q->next = p;
      q = p;
    }
  }

  // ...

  return;
}

int Graph::sputil(char Vt) {
  node *m = nullptr;
  int LowDv;  // Lowest Distance Value
  p = start;

  while (p != nullptr) {
    if (p->data != start->data) {
      p->DistanceValue = 9999;
    } else {
      p->DistanceValue = 0;
    }
    p->status = 0;
    p = p->next;
  }

  while (1) {
    p = start;
    LowDv = 9999;  // highest distance value to start with
    while (p != nullptr) {
      if (p->DistanceValue <= LowDv && p->status != 1) {
        LowDv = p->DistanceValue;
        q = p;
      }
      p = p->next;
    }

    if (q->data == Vt) {
      break;
    }
    k = q->adj;
    q->status = 1;

    while (k != nullptr) {
      m = k->next;
      if ((q->DistanceValue + k->weight) < m->DistanceValue) {
        m->DistanceValue = q->DistanceValue + k->weight;
      }
      k = k->adj;
    }
  }

  return q->DistanceValue;
}

int main() {
  char vs, vt;
  int shortest_distance = 0;

  Graph graphobj;
  vs = graphobj.getstart();
  cout << "\nEnter the terminal vertex: ";
  cin >> vt;

  shortest_distance = graphobj.sputil(vt);

  cout << "\nThe shortest distance between " << vs << " and " << vt << " is " << shortest_distance;

  return 0;
}
