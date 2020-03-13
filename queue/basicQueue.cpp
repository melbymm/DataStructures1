#include "basicQueue.h"

basicQueue::basicQueue(){
  newQueue = new char[200];
  mSize = 200;
  front = 0;
  back = -1;
  elementNum = 0;
}

basicQueue::basicQueue(int limit){
  newQueue = new char[limit];
  mSize = limit;
  front = 0;
  back = -1;
  elementNum = 0;

}

basicQueue::~basicQueue(){
  delete basicQueue;
}

void basicQueue :: insert(char c){
  newQueue[++rear] = c;
  ++elementNum;
}
char basicQueue :: remove(){
  char b = "\0";
  ++front;
  --elementNum;
  return b;
}
bool basicQueue :: full(){
  return (elementNum == mSize);
}
bool basicQueue :: empty(){
  return (elementNum == 0);
}
char basicQueue :: peek(){
  return newQueue[front];
}
int basicQueue :: getSize(){
  return elementNum;
}
