#include "linkedList.h"

naiveList :: naiveList(){
  size = 0;
  front = NULL;
}
naiveList :: ~naiveList(){

}
unsigned int naiveList :: getsize(){
  return size;
}
bool naiveList :: isEmpty(){
  retun (size == 0);
}
void naiveList :: printList(){
  listNode *current = front;
  while (current != NULL){
    cout << current -> data << endl;
    curr = current -> next;
  }
}
void naiveList :: insertFront(int d){
  listNode *node = new listNode(d);
  node -> next = front;
  front = node;

  size ++;
}
void naiveList :: removeFront(){
  if(!isEmpty){
  	Int temp = front -> data;
  	listNode *ft = front;
  	Front = front -> next;
  	Ft -> next = NULL;
  	Delete ft;

    --size;
    Return temp;
  }
}

void naiveList :: search(int val){
  int pos = -1;
  listNode *current = front;

  while(current != NULL){
    ++pos;
    if(current -> data = val){
      break;
    }
    else{
      current = current -> next;
    }
  }
  if(curr == NULL){
    cout << "Couldn't find it." << endl;
    pos = -1;
  }
  return pos;
}

void naiveList :: removeAtPos(int pos){
  int idx = 0;
  if(pos < naiveList.size()){
    listNode *current = front;
    listNode *prev = front;
    while(idx != pos){
      prev = current;
      current = current -> next;
      idx++;
    }
    if(idx = pos){
      prev -> next = current -> next;
      current -> next = NULL;
      int temp = current -> data;
      delete current;
      size --;
      return temp;
    }
  }
}
