#include <iostream>
using namespace std;

struct node {
  int info;
  struct node *link;
};

class LinkedList {
  private:
    node *start;

  public:
    LinkedList() {
      start = NULL;
    }
  void InsertAtFrontNode();
  void InsertAfterNode();
  void DeleteFrontNode();
  void DeleteGivenNode();
  void Display();
};

void LinkedList::InsertAtFrontNode() {
  int data;
  node *temp = new node;
  if (temp == NULL) {
    cout << "Overflow of memory, exiting the program." << endl;
    exit(0);
  }

  cout << "\nEnter the data to be inserted ";
  cin >> data;
  temp->info = data;
  temp->link = NULL;

  // check if FIRST NODE
  if (start == NULL) {
    start = temp;
  } 
  else {
    temp->link = start;
    start = temp;
  }
}

void LinkedList::InsertAfterNode() {
  node *temp = new node, *searchnode, *insertloc;
  int data, searchdata;
  if (temp == NULL)
  {
    cout << "Overflow of memory, exiting the program." << endl;
    exit(0);
  }
  cout << "\nEnter the data to be inserted ";
  cin >> data;
  temp->info = data;
  temp->link = NULL;

  cout << "\nEnter the node after which the new node has to be inserted: ";
  cin >> searchdata;
  searchnode = start;
  insertloc = NULL;

  while (searchnode != NULL) {
    if (searchnode->info == searchdata) {
      insertloc = searchnode;
      break;
    }
    else {
      searchnode = searchnode->link;
    }
  }

  if (insertloc != NULL) {
    temp->link = insertloc->link;
    insertloc->link = temp;
  }
  else {
    cout << "\nEither the list is empty or search node is not found.";
    cout << "Inserting new node at the front. \n";
    temp->link = start;
    start = temp;
  }
}

void LinkedList::DeleteFrontNode() {
  node *temp;
  if (start != NULL) {
    temp = start;
    start = start->link;
    delete temp;
  }
  else {
    cout << "List is empty, nothing to delete. \n";
  }
}

void LinkedList::DeleteGivenNode() {
  int searchdata;
  node *searchnode, *previousnode, *deleteloc;
  cout <<"\nEnter the node value to be deleted: ";
  cin >> searchdata;
  searchnode = start;
  previousnode = NULL;
  deleteloc = NULL;

  while (searchnode != NULL) {
    if (searchnode->info == searchdata) {
      deleteloc = searchnode;
      break;
    }
    else {
      previousnode = searchnode;
      searchnode = searchnode->link;
    }
  }

  if (deleteloc != NULL) {
    if (deleteloc == start) {
      start = start->link;
    }
    else {
      previousnode->link = deleteloc->link;
    }
    delete deleteloc;
  }
  else {
    cout << "\nElement to be deleted does not exist. \n";
  }
}



int main() {
  cout << "Hello World!!\n";



  return 0;
}