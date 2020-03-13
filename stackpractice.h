#include <iostream>
using namespace std;

class GenStack{
  public:
    GenStack();
    GenStack(int maxsize);
    ~GenStack(); //destructor

    //core functions
    void push(char data);//insert
    char pop();

    //aux functions
    char peak();//top

    bool isEmpty();
    bool isFull();
    int mSize;
    int top;

    char *myArray;

    
}
