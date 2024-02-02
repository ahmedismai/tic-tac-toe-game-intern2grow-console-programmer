#include<iostream>
using namespace std;

class XO_Board
{
    public:
        void drawBoard(char Board[3][3])
        {
            cout<<"-------------\n";
            for(int i=0;i<3;++i)
            {
                cout<<"| ";
                for(int j=0;j<3;++j)
                {
                    cout<<Board[j][i]<<" | ";
                }
                cout<<"\n-------------\n";
            }
        }
};