#include <iostream>
#include <stdlib.h>
#include <conio.h>
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

void LinkedList::Display() {
  node *p;
  p = start;
  if (start == NULL) {
    cout << "List is empty.\n";
  }
  else {
    cout << "\nCONTENTS OF THE LIST ARE: | ";
    while (p != NULL) {
      cout << p->info;
      cout << " ";
      p = p->link;
    }
    cout << "|\n";
  }
}

int main() {
  system("cls");

  LinkedList linklist;
  int choice;

  while(1) {
    cout << "\n1. Insert at front of linked list.";
    cout << "\n2. Insert after given element.";
    cout << "\n3. Delete the front node of linked list.";
    cout << "\n4. Delete a given element.";
    cout << "\n5. Display linked list elements.";
    cout << "\n6. Exit.";
    cout << "\nENTER YOUR CHOICE: ";

    cin >> choice;

    switch(choice) {
      case 1: linklist.InsertAtFrontNode();
              break;
      case 2: linklist.InsertAfterNode();
              break;
      case 3: linklist.DeleteFrontNode();
              break;
      case 4: linklist.DeleteGivenNode();
              break;
      case 5: linklist.Display();
              break;
      case 6: exit(0);

      default: 
        cout << "\nSorry your answer is incorrect!! Please enter correct choice (1-6)\n";    
    }
  }
  
  return 0;
}