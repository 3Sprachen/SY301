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
    LL();//LL(int x, Node(int x, Node *NN));
    Node *Head;
    Node *Tail;
  //  Node *current;
    void printLL();
    void isin(int);
    void add2front(int);
    void add2back(int);
    void addinorder(int);

};

LL::LL(){
  Head = NULL;
  Tail = NULL;
  //data = x;
}
void LL::add2front(int x){
  //int tmp;

  if (Head == NULL){//got this if statement but not sold on it. Might get rid of it.
  //  cout << "add2front" << endl;
    Node *tmp = new Node(x);
    //tmp -> NN = Head;
    Head = tmp;
    Tail = Head;
  }else{
    Node *tmp = new Node(x);
    tmp -> NN = Head;
    Head = tmp;
    //cout << "add2front succeeded" << endl;
  }
  //cout << "(add2front completed)" << endl;
  //printLL();
}
void LL::add2back(int x){ // just modified add2front. Check this
  //int tmp;
  if (Tail == NULL){
  //  cout << "add2back" <<endl;
    Node *tmp = new Node(x);
    tmp -> NN = Tail;
    Head = tmp; //idk bout this
    Tail = tmp;

  }else {
    Node *current = Head;
    while (current -> NN != NULL){
      current = current -> NN;
    }
    Node *tmp = new Node(x);
    tmp -> NN =NULL;
    Tail = tmp;
    current -> NN = tmp;
  }
  //cout << "(add2back completed)" << endl;
  //printLL();
}
void LL::isin(int x){
  Node *current = Head;
  char* middle = "IS NOT";
  while (current -> NN != NULL) {
    if (current -> data == x){
      middle = "IS";
      break;
    }else {
      current = current -> NN;
    }
  }
  cout << x << " " << middle << " in the list." << endl;


}

void LL::addinorder(int x){
  int added = 0; //to keep us from adding the same node twice
  Node *current = Head;
  Node *previous = Head;
  if (current -> data > x){
    add2front(x);
    added = 1;
  }
  while (current -> data < x and added == 0){
    previous = current;
    current = current -> NN;
    if (current -> NN == NULL){ //had issue with item getting added twice. Added variable fixes it
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
    //NN -> data = x;
  //cout << "(addinorder completed)" << endl;
  //printLL();
}
void LL::printLL(){
  Node * current = Head;
  cout << "List contains: " << endl;
  while (current -> NN != NULL){
    cout << current -> data << endl;
    current = current -> NN;
  }
  cout << current -> data << endl;
  //cout << "printLL succeeded" << endl;
}



int main()
{
LL list;          // LL is the name of the linked list class and list is one instance of that class

  list.add2front(5);
  list.add2back(10);
  list.addinorder(17);
  list.addinorder(2000);
  list.addinorder(-1);
  list.addinorder(6);
  list.addinorder(2020);
  list.isin(17);
  list.isin(9);
  list.printLL();

return 0;
}
