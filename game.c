#include"game.h"
void initBoard(int board[3][3])
{
    for (int i=0;i<grid_size;i++)
    {
        for (int j=0;j<grid_size;j++)
        {
            board[i][j]=0;
        }
    }
    return;
}
 int iscellempty(int board[3][3], int row, int col)
 {
    if (board[row][col]==0)
    return 1;
    else
    return 0;

 }
 void makemove(int board[3][3], int row, int col, int player)
 {
    board[row][col]=player;
    return;
 }
 int checkwin(int board[3][3])
 {
    for(int i=0;i<3;i++)
    { if (board[i][0]!=0 && board[i][0]==board[i][1] && board[i][1]==board[i][2])
        return board[i][0];

        if(board[0][i]!=0 && board[0][i]==board[1][i] && board[1][i]==board[2][i])
        return board[0][i];
    }
    if (board[0][0]!=0 && board[0][0]==board[1][1] && board[2][2]==board[1][1])
    return board[0][0];
    if(board[0][2]!=0 && board[0][2]==board[1][1] && board[2][0]==board[1][1])
    return board[0][2];

    return 0;
 }