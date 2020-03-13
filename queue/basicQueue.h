#include <iostream>
using namespace std;

class basicQueue{
  public:
    basicQueue();
    basicQueue(int limit);
    ~basicQueue();

    void insert(char c);
    char remove();

    char peek();
    bool full();
    bool empty();
    int getSize();

    int front;
    int back;
    int mSize;
    int elementNum;

    char *myQueue;



};
