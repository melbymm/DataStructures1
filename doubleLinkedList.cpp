#include "linkedList.h"

doubleNaiveList :: naiveList(){
  size = 0;
  front = NULL;
  back = NULL;
}
doubleNaiveList :: ~naiveList(){

}
unsigned int doubleNaiveList :: getsize(){
  return size;
}
bool doubleNaiveList :: isEmpty(){
  retun (size == 0);
}
void doubleNaiveList :: printList(){
  listNode *current = front;
  while (current != NULL){
    cout << current -> data << endl;
    curr = current -> next;
  }
}
void doubleNaiveList :: insertFront(int d){
  listNode *node = new listNode(d);
  if(!isEmpty()){

    front -> node;
    node -> next = front;
}
  else(){
    back = node;
  }


  size ++;
}
void doubleNaiveList :: removeFront(){
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

void doubleNaiveList :: search(int val){
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

void doubleNaiveList :: removeAtPos(int pos){
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
void doubleNaiveList :: insertBack(int d){
  listNode *node = new listNode(d);
  if(!isEmpty()){

    back -> next = node;
    node ->prev = back
}
  else(){
    front = node;
  }
  back = node;
  size ++;
}
