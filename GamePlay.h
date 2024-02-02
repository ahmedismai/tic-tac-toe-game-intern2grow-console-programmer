#include <iostream>
#include "TicTac.h"
using namespace std;

class CheckWin
{
    public:
    bool IsWinner(char board[3][3], char player) 
{ 
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == player && board[i][1] == player 
            && board[i][2] == player) 
            return true; 

        if (board[0][i] == player && board[1][i] == player 
            && board[2][i] == player) 
            return true; 
    } 

    if (board[0][0] == player && board[1][1] == player 
        && board[2][2] == player) 
        return true; 

    if (board[0][2] == player && board[1][1] == player 
        && board[2][0] == player) 
        return true; 
        
    return false; 
} 
    
};