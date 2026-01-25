
#ifndef GAME_H
#define GAME_H
#define grid_size 3


void initBoard(int board[3][3]);
int iscellempty(int board[3][3], int row, int col);
void makemove(int board[3][3], int row, int col, int player);
int isboardfull(int board[3][3]);
int checkwin(int board[3][3]);
void resetgame(int board[3][3], int *player,int *gameover);
 #endif


  

