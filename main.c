#include"raylib.h"
#include<stdio.h>
#include"game.h"
int main(void)
{
    const int screenWidth=800; 
    const int screenHeight=750;
    InitWindow(screenWidth,screenHeight,"h" );
    SetTargetFPS(60);
    int boardx=200,boardy=200,cell_size=100;
    int player=1, gameover=0;
    int board[3][3];
    
   initBoard(board);
    
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
            printf("Mouse: %f %f\n", mouse.x, mouse.y);
            if (mouse.x>=boardx && mouse.x<boardx +cell_size*grid_size 
                && mouse.y>=boardy && mouse.y<boardy+cell_size*grid_size)
            {
               int col=(mouse.x-boardx)/cell_size;
               int row=(mouse.y-boardy)/cell_size;
               if (!gameover && iscellempty(board,row,col))
               {printf("row=%d col=%d\n", row, col);

                 makemove(board,row,col,player);
                 if(checkwin(board)==1)
                    gameover=1;
                    
                 else if(checkwin(board)==2)
                 
                    gameover=2;
                 else
                 player=(player==1)?2:1;
                
               }
               
            }
            
        }
        for(int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if(board[i][j]==1)
                DrawText("X ",boardx+j*cell_size+50, boardy+i*cell_size+50, 30, WHITE);
                else if (board[i][j]==2)
                DrawCircleLines(boardx+j*cell_size+50, boardy+i*cell_size+50,10, WHITE);
            }
        }
        if (gameover == 1)
           DrawText("Player 1 won", 300, 600, 20, WHITE);
        else if (gameover == 2)
           DrawText("Player 2 won", 300, 600, 20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;

}
