#include <iostream>
#include <sstream>
#include <fstream>
#include "listNode.h"


class doubleNaiveList{
  public:
    doubleNaiveList();
    ~doubleNaiveList();
    void insertFront(int d);
    int removeFront();
    int search(int val);
    int removeAtPos(int pos);
    void insertBack(int d);
    int removeBack();

    unsigned int getsize();
    bool isEmpty();
    void printList();
    void removeFront();
    listNode *front;
    listNode *back;
    unsigned int size = 0;



  private:
    listNode *front;
    //listNode *next;
    unsigned int size;

}
