#include "basicQueue.h"

int main (int argc, char **argv){
  basicQueue *bq = new basicQueue[10];

  bq -> insert('t');
  bq -> insert('e');
  bq -> insert('s');
  bq -> insert('t');

  cout << "First char: " << q->peek() << endl;

  delete bq;

  
}
