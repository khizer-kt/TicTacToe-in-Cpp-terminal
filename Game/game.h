#include <iostream>
#include <string>
using namespace std; //STANDARD LIBRARIES

class TicTacToe {
char move_; //TURNS OF PLAYERS
int entry; //ENTRANCE OF MOVES
public:
    int arr[3][3]; //2-Dimensional Array
    void base(); //BASIC GAME STRUCTURE
    TicTacToe(); //CONSTRUCTOR
    void gamelogic(); //GAMELOGIC

};
