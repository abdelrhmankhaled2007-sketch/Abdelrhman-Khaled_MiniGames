#include <iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std; 
void display(char grid[3][3], char player=' ')
{
    cout<<"-------------\n";
    for(int i=0; i<3; i++)
    {
        cout<<"| ";
        for(int j=0; j<3; j++)
        {
            cout<<grid[i][j]<<" | ";
        }
        if(i!=2)
            cout<<"\n----+---+----\n";
        else
            cout<<"\n-------------\n";
    }
    if(player!=' ')
        cout<<"Player "<<player<<" Enter you move choose (1:3),(1,3):";
}
bool ValidMove(int r, int c, char grid[3][3])
{
    if(r>=0 && r<=2 && c>=0 && c<=2 && grid[r][c]=='-')
        return true;
    else
        return false;
}
bool IsWinner(char grid[3][3], char player)
{
    for(int i=0; i<3; i++)  //column
    {
        if( grid[i][0]==player && grid[i][1]==player &&grid[i][2]==player)
            return true;
        if( grid[0][i]==player && grid[1][i]==player &&grid[2][i]==player)
            return true;
    }
    if(grid[0][0]==player&&grid[1][1]==player&&grid[2][2]==player)
        return true;
    if(grid[0][2]==player&&grid[1][1]==player&&grid[2][0]==player)
        return true;
    return false;
}
bool IsDraw(char grid[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            if(grid[i][j]=='-')
                return false;
    }
    return true;
}
void XO_Game()
{
    int rounds;
    int scoreX = 0, scoreO = 0, draws = 0;

    cout << "Enter number of rounds: ";
    cin >> rounds;

    for(int round = 1; round <= rounds; round++)
    {
        cout << "\n===== Round " << round << " =====\n";

        char grid[3][3] =
        {
            {'-','-','-'},
            {'-','-','-'},
            {'-','-','-'}
        };

        char player = 'X';
        int r, c;

        while(true)
        {
            display(grid, player);
            cin >> r >> c;
            r--,c--;
            if(ValidMove(r, c, grid))
            {
                grid[r][c] = player;
                if(IsWinner(grid, player))
                {
                    display(grid);
                    cout << "Player " << player << " wins this round!\n";

                    if(player == 'X')
                        scoreX++;
                    else
                        scoreO++;

                    break;
                }
                if(IsDraw(grid))
                {
                    display(grid);
                    cout << "Game is draw\n";
                    draws++;
                    break;
                }
                player = (player == 'X') ? 'O' : 'X';
            }
            else
            {
                cout << "Invalid try again\n";
            }
        }
        if(round < rounds)
        {
            cout << "\n===== Current Score =====\n";
            cout << "Player X: " << scoreX << endl;
            cout << "Player O: " << scoreO << endl;
            cout << "Draws: " << draws << endl;
        }
    }
    cout << "\n===== FINAL RESULT =====\n";

    cout << "Player X: " << scoreX << endl;
    cout << "Player O: " << scoreO << endl;
    cout << "Draws: " << draws << endl;

    if(scoreX > scoreO)
        cout << "Player X is the Winner!\n";
    else if(scoreO > scoreX)
        cout << "Player O is the Winner!\n";
    else
        cout << "The Game is Draw!\n";
}
int main()
{
    XO_Game();
    return 0;
}



