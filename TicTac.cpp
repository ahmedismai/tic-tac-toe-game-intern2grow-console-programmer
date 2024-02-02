#include <iostream>
#include <fstream>
using namespace std;
#include "GamePlay.h"

int main()
{   
    fstream MyFile;
    MyFile.open("filename.txt");
  
    string read;
    getline(MyFile, read);

    MyFile >> read;
    int xCount = stoi(read);

    MyFile >> read;
    int oCount = stoi(read);

    MyFile.close();
  
 
    XO_Board b;
    CheckWin c;
    char Board[3][3]={{ ' ', ' ', ' ' }, 
                      { ' ', ' ', ' ' }, 
                      { ' ', ' ', ' ' }};

    char Player1 = 'X' , Player2 = 'O';
    int Row , Row1;
    int Col , Col1;
    int count = 0;
    int X = 0;
    int O = 0;


    MyFile.open("filename.txt");

    for(count = 0;count < 9;)
    {
        b.drawBoard(Board);

        while (count < 9)
        {
            cout << "Player1 " << Player1 << ", enter row (0-2) and column (0-2): "; 
            cin >> Row >> Col; 
    
            if (Board[Col][Row] != ' ' || Row < 0 || Row > 2  || Col < 0 || Col > 2) { 
                cout << "Invalid move. Try again.\n"; 
            } 
            else {
                count++;
                break;
            }
            
        }
        
        Board[Col][Row] = Player1;

        if (c.IsWinner(Board, Player1)) { 
            b.drawBoard(Board); 
            cout << "Player1 " << Player1 << " wins!\n"; 
            xCount++;
            MyFile << "X\tO\n";
            MyFile << xCount<< "\t" << oCount << "\n";
            cout << "Player1" << "\t" << "Player2" <<"\n";
            cout << xCount << "\t" << oCount << "\n";
            break; 
        } 
        b.drawBoard(Board);

        while (count < 9)
        {
            cout << "Player2 " << Player2 << ", enter row (0-2) and column (0-2): "; 
            cin >> Row1 >> Col1; 

            if (Board[Col1][Row1] != ' ' || Row1 < 0 || Row1 > 2 || Col1 < 0 || Col1 > 2) { 
                cout << "Invalid move. Try again.\n"; 
            } 
            else { 
                count++;
                break; 
            }    
        } 
            
        Board[Col1][Row1]=Player2;

           
        if (c.IsWinner(Board, Player2)) { 
            b.drawBoard(Board); 
            cout << "Player2 " << Player2 << " wins!\n"; 
            oCount++;
            MyFile << "X\tO\n";
            MyFile << xCount << "\t" << oCount << "\n";
            cout << "Player1" << "\t" << "Player2" << "\n";
            cout << xCount << "\t" << oCount << "\n";
            break;  
        } 
    }

    MyFile.close();

    MyFile.open("filename.txt");
    b.drawBoard(Board);
   
    if (count == 9 && !c.IsWinner(Board, Player1) && !c.IsWinner(Board, Player2)) { 
        cout << "It's a draw!\n"; 
        MyFile << "X\tO\n";
        MyFile << xCount << "\t" << oCount << "\n";
        cout<< "Player1" << "\t" << "Player2" << "\n";
        cout << xCount << "\t" << oCount << "\n";
    }

    MyFile.close();
    return 0;
}

