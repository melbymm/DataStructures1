#include <iostream>
#include <sstream>
#include <fstream>


class naiveList{
  public:
    naiveList();
    ~naiveList();
    void insertFront(int d);
    int removeFront();
    int search(int val);
    int removeAtPos(int pos);

    unsigned int getsize();
    bool isEmpty();
    void printList();
    void removeFront();
    


  private:
    listNode *front;
    //listNode *next;
    unsigned int size;

}
