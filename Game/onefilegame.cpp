#INCASE OF ANY ERROR WHISLT INCLUDING THE ADDITIONAL FILES RUNS THIS
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


TicTacToe::TicTacToe() { //CONSTRUCTOR TO INITIALIZE ARRAY AND MOVE
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    arr[1][0] = 0;
    arr[1][1] = 0;
    arr[1][2] = 0;
    arr[2][0] = 0;
    arr[2][1] = 0;
    arr[2][2] = 0;
    move_ = '1';
}



void TicTacToe::base() { //MEMBER FUNCTION TO CREATE BOARD
    cout << " " << endl;

    for (int i = 0; i < 3; i++) {        //NESTED FOR LOOP TO PRINT THE BOARD PATTERN
        for (int j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j];
            if (j <= 1)
                cout << " |";
            else
                cout << endl;
            if (j == 2 && i < 2)
                cout << "" << endl;
        }
    }
}
void TicTacToe::gamelogic() { //MEMBER FUNCTION FOR GAME LOGIC
    for (int i = 0; i < 9; i++)
        {
        if (move_ == '1') { //PLAYER 1  HAS DEFAULT TURN AND THEN TURN SHIFTS TO PLAYER 2 AND BACK TO 1
            cout << "Player 1 Turn: " << endl;
        }
        else if (move_ == '2') {
            cout << "Player 2 Turn: " << endl;
        }
        int row, column; //ASKING AT WHICH POSITION YOU WANT TO MAKE A MOVE AT
        cout << "Positioning Starts from Top Left (1) to Bottom Right (9)" << endl;
        cout << "Enter at which position you want to mark at: " << endl;
        cin >> entry;
        switch (entry) { //SWITCHING TO ALLOW ONLY VALID ENTRY POINTS
        case 1: row = 0; column = 0;
            break;
        case 2: row = 0; column = 1;
            break;
        case 3: row = 0; column = 2;
            break;
        case 4: row = 1; column = 0;
            break;
        case 5: row = 1; column = 1;
            break;
        case 6: row = 1; column = 2;
            break;
        case 7: row = 2; column = 0;
            break;
        case 8: row = 2; column = 1;
            break;
        case 9: row = 2; column = 2;
            break;
        }
        if (entry >9 || entry < 1){
            cout << "Invalid Entry Position" << endl;
            break;
        }
        //PLACING THE VALID SYMBOLS FOR THE PLAYERS TURNS
        if (move_ == '1' && arr[row][column] != 1 && arr[row][column] != 2) {//WHEN P1 MOVES AND SPACE NOT OCCUPIED
            arr[row][column] = 1;
            move_ = '2';
        }
        else if (move_ == '2' && arr[row][column] != 2 && arr[row][column] != 1) {//WHEN P1 MOVES AND SPACE NOT OCCUPIED
            arr[row][column] = 2;
            move_ = '1';
        }
        else {
            cout << "Box is already filled in Chose another box " << endl; //WHEN BOX ALREADY FILLED
            gamelogic();
        }
        base(); //RECALLING BASE EVERY TIME WHEN THE ARRAY IS APPENDED BY THE PLAYERS
        //CHECKING IF EITHER OF THE PLAYERS WIN
        if ((arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1) || (arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1) || (arr[2][0] == 1 && arr[2][1] == 1 && arr[2][2] == 1) || (arr[0][0] == 1 && arr[1][0] == 1 && arr[2][0] == 1) || (arr[0][1] == 1 && arr[1][1] == 1 && arr[2][1] == 1) || (arr[0][1] == 1 && arr[1][1] == 1 && arr[2][1] == 1) || (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1) || (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1))
        {
            cout << "Player 1 WINS" << endl;
            break;
        }
        else if ((arr[0][0] == 2 && arr[0][1] == 2 && arr[0][2] == 2) || (arr[1][0] == 2 && arr[1][1] == 2 && arr[1][2] == 2) || (arr[2][0] == 2 && arr[2][1] == 2 && arr[2][2] == 2) || (arr[0][0] == 2 && arr[1][0] == 2 && arr[2][0] == 2) || (arr[0][1] == 2 && arr[1][1] == 2 && arr[2][1] == 2) || (arr[0][1] == 2 && arr[1][1] == 2 && arr[2][1] == 2) || (arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2) || (arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2)) {
            cout << "Player 2 WINS" << endl;
            break;
        }
        //WHEN ALL BOXES ARE FILLED BUT NO ONE WINS
        else if (i==8){
            cout << "DRAW" << endl;
        }
    }
}

int main() {
    TicTacToe g;
    g.base();
    g.gamelogic();
    return 0;
}
