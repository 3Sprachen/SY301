#include <iostream>
#include <stdio.h>

using namespace std;

class Node {
  public:
    int data;
    Node *NN;
    Node(int x);

};

Node::Node(int x){
  data = x;
  NN = NULL;

}

class LL {
  public:
    LL();
    int count;
    Node * N;
    Node *Head;
    Node *Tail;
    void printLL(Node *);
    void isin(int);
    void add2front(int);
    void add2back(int);
    void addinorder(int);
    int addcount;
    int backcount;
    int isincount;


};

LL::LL(){
  Head = NULL;
  Tail = NULL;
  backcount = 0;
  addcount = 0;
  count = 0;
  isincount = 0;
  N = Head;
  //Node* current = Head;
  //Node *previous = Head;
  //added = 0;

}
void LL::add2front(int x){
  if (Head == NULL){//got this if statement but not sold on it. Might get rid of it.

    Node *tmp = new Node(x);

    Head = tmp;
    Tail = Head;
  }else{
    Node *tmp = new Node(x);
    tmp -> NN = Head;
    Head = tmp;

  }

}
void LL::add2back(int x){

  if (Tail == NULL){ //if this is the first element in the list
    Node *tmp = new Node(x);
    tmp -> NN = Tail;
    Head = tmp;
    Tail = tmp;

  }else { //not first element, so we have to add it to back
    if (backcount == 0){
    Node *current = Head;
    backcount++;
    }else{
      if(current -> NN != NULL){
      current = current -> NN;
      add2back(current -> NN);
      backcount++;
    }
    }
    Node *tmp = new Node(x);
    tmp -> NN = NULL;
    Tail = tmp;
    current -> NN = tmp;
  }

}
void LL::isin(int x){
  if (isincount == 0){
  Node *current = Head;
  char* middle = "is not";
  isincount ++;
  }

  if (current -> NN != NULL) {
    if (current -> data != x){
      current = current -> NN;
      isin(x);
    }else{
      middle = "is";

    }
  }
  isincount++;
  cout << x << " " << middle << " in the list." << endl;


}

void LL::addinorder(int x){
  if (addcount == 0){
  int added = 0; //to keep us from adding the same node twice
  Node *current = Head;
  Node *previous = Head;
  }
  if (current -> data > x){
    add2front(x);
    added = 1;
  }

  else if (current -> data < x and added == 0){
    previous = current;
    current = current -> NN;
    addinorder(x);
    if (current -> NN == NULL){ //had issue with item getting added to the list twice. "added" variable fixes it
      add2back(x);
      added = 1;
    }
  }
  //insert it here
  if (added == 0){ //we didn't add the new one yet
    Node* tmp = new Node(x);
    tmp -> NN = current;
    previous -> NN = tmp;
  }

}
void LL::printLL(Node * N){

  if (count == 0){
    //N = Head;//initialized elsewhere
    cout << "Linked List contains:" << endl;
    count ++;
  }else{
  cout << N -> data << endl;
  printLL(N -> NN);
  count ++; //
  }
}

int main()
{
LL list;          // LL is the name of the linked list class and list is one instance of that class
Node *N;          //can call like printLL(N);
  list.add2front(5);
  list.add2back(10);
  list.addinorder(17);
  list.addinorder(2000);
  list.addinorder(-1);
  list.addinorder(6);
  list.addinorder(2020);
  list.isin(17);
  list.isin(9);
  list.printLL(N);

return 0;
}
