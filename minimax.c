#include<stdio.h>
#include<raylib.h>

#define PLAYER 'X' 
#define AI 'O'
#define grid_size 3
void initBoard(char board[3][3])
{
    for (int i=0;i<grid_size;i++)
    {
        for (int j=0;j<grid_size;j++)
        {
            board[i][j]=' ';
        }
    }
    return;
}
int cellempty(char board[3][3],int l, int m)
{
    if (board[l][m]==' ')
    return 1;
    else
    return 0;
}
int boardisfull(char board[3][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (board[i][j]==' ')
            return 0;
        }
    }
    return 1;
}
int checkwin(char board[3][3])
{
    for (int i=0;i<3;i++)
    {
        if (board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ' )
        {
            if (board[i][0]==PLAYER)
             return -10;
            else if (board[i][0]==AI)
             return 10;
        }
    }
     for (int i=0;i<3;i++)
    {
        if (board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' '  )
        {
            if (board[0][i]==PLAYER)
             return -10;
            else if (board[0][i]==AI)
             return 10;
        }
    }
    if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=' ' )
    {
         if (board[0][0]==PLAYER)
             return -10;
            else if (board[0][0]==AI)
             return 10; 
    }
    if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[2][0]!=' ' ) 
    {
        if (board[0][2]==PLAYER)
             return -10;
            else if (board[0][2]==AI)
             return 10;
    }
    return 0;
}
int minimax(char board[3][3],int depth,int ismaximizing)
{  
    int bestscore,score,state=checkwin(board);
    if (state==10)
    return 10 - depth;
    else if (state==-10)
    return -10 + depth;
    else if (boardisfull(board))
    return 0;
    if (ismaximizing==1)
    { bestscore=-100;
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (board[i][j]==' ')
                 {board[i][j]=AI;
                 score = minimax(board,depth+1,0);
                 board[i][j]=' ';
                if (bestscore<score)
                 bestscore=score;
            }
            }
        }
        return bestscore;
    }
    else
    { bestscore=100;
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (board[i][j]==' ')
                {
                 board[i][j]=PLAYER;
                 score = minimax(board,depth+1,1);
                 board[i][j]=' ';
                if (bestscore>score)
                 bestscore=score;
                }
            }
        }
        return bestscore;
    }

    }
    void bestmove(char board[3][3])
    { int bestscore=-100,score;
      int row=-1;
      int col=-1;
      for (int i=0;i<3;i++)
      {
        for (int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]=AI;
                score=minimax(board,0,0);
                board[i][j]=' ';
                if (score>bestscore)
                {
                    bestscore=score;
                    row=i;
                    col=j;

                }
            
            }

        }
      }

    board[row][col]=AI;
    }
    
void resetgame(char board[3][3], char *player, int *gameover)
 {
   initBoard(board);
   *player=PLAYER;
   *gameover=0;
 }
                 
      

    
    

int main()
{   const int screenWidth=800; 
    const int screenHeight=750;
    InitWindow(screenWidth,screenHeight,"h" );
    SetTargetFPS(60);
    int boardx=200,boardy=200,cell_size=100;
    char board[3][3]; int l,m; char PLAYER1=PLAYER;
    initBoard(board);
    int gameover=0;
    while(!WindowShouldClose())

    {
         BeginDrawing();
         ClearBackground(BLACK);
        
         DrawText("TIC TAC TOE",300,80,20,WHITE);
        for (int i=1;i<grid_size;i++)
        {
            DrawLine(boardx,
                boardy+i*cell_size,
                boardx+grid_size*cell_size,
                boardy+i*cell_size,WHITE);
            DrawLine(boardx +i*cell_size,
                boardy,
                boardx +i*cell_size,
                boardy+cell_size*grid_size,WHITE);
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse=GetMousePosition();
            
            if (mouse.x>=boardx && mouse.x<boardx +cell_size*grid_size 
                && mouse.y>=boardy && mouse.y<boardy+cell_size*grid_size)
            {
               int col=(mouse.x-boardx)/cell_size;
               int row=(mouse.y-boardy)/cell_size;
               if (!gameover && cellempty(board,row,col))
               {
                board[row][col]=PLAYER1;
               
            if (checkwin(board)==-10)
            {
                 gameover=2;
                 
            }
            else if (boardisfull(board))
             {
                 gameover=3;
             }
              else 
            {
              bestmove(board);
              int state=checkwin(board);
              if (state==10)
              gameover=1;
              else if (boardisfull(board))
              gameover=3;
            } 
         }
    }
 if (mouse.x>=390 && mouse.x<=500 && mouse.y>=700 && mouse.y<=725)
        {
           resetgame(board,&PLAYER1,&gameover);
        }}

    for(int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if(board[i][j]==PLAYER)
                DrawText("*",boardx+j*cell_size+50, boardy+i*cell_size+50, 30, WHITE);
                else if (board[i][j]==AI)
                DrawCircleLines(boardx+j*cell_size+50, boardy+i*cell_size+50,10, WHITE);
            }
        }
        if (gameover == 2)
           DrawText("Player won", 300, 600, 20, WHITE);
        else if (gameover == 1)
           DrawText("AI won", 300, 600, 20, WHITE);
        else if (gameover==3)
         DrawText("DRAW", 300, 600, 20, WHITE);
        DrawRectangle(390,700,110,25,GREEN);
        DrawText("RESTART", 400,700,20,WHITE);

         EndDrawing();
}
CloseWindow();
    return 0;
}