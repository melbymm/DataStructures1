#include "stackpractice.h"

GenStack::GenStack(){
  myArray = new char[200];
  mSize = 200;
  top = -1;
}
GenStack::GenStack(int maxsize){
  myArray = new char[maxsize];
  mSize = maxsize;
  top = -1;

}

GenStack::GenStack(){
  delete myArray;
}

void GenStack::push(char data){
  if(!isFull){
    myArray[++top] = data;
  }
}
