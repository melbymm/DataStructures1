#include "board.h"

board :: askBoard(){
  cout << "Would you like to (1) Use a random board, or (2) enter your own board?: " << endl;
  cin >> ownboard;
  if (ownboard == 1){
    cout << "What do you want to be the width dimension to be?: "
    cin >> width;
    cout << "What do you want to be the height dimension to be?: "
    cin >> height;
  }
  else if (ownboard == 2){
    cout << "Enter your board: " << endl;
  }
  else{
    cout << "enter valid input."
    break;
  }
}
board :: makeBoard(){
  board = new char [width][height];
}
