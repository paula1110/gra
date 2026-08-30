#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>
#include<thread>
#include<conio.h>



using namespace std;
char board[10][20]=
{{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
 {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},

{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

bool check_lose(char board[10][20],int x,int y)
{
    if(board[x][y]=='#')
     return false;

     return true;
}

void print_board(char board[10][20])
{
    for(int i=0;i<10;i++)
    {
       for(int j=0;j<20;j++)
       {
        cout<<board[i][j];
       }
       cout<<endl;
    }
}
struct food{
    int x;
    int y;
};
void new_food(char board[10][20])
{
   // srand(time(0));
    food result;
    result.x = rand() % 8+1;
    result.y= rand() % 18+1;
    board[result.x][result.y]='*';
}
void check_food(char board[10][20],int x,int y,int score)
{
    if(board[x][y]=='*')
    new_food(board);
    score++;
}


int main()
{
     srand(static_cast<unsigned int>(time(nullptr)));
    int score =0;
    int foodx;
    int foody;
    
    int x=1,y=1;
    char direction='d';
    char m;
    char d='d';
    vector<char> snake ={'O'};
    new_food(board);
    print_board(board);
    while (true)
    {
     cout<<score;   
       if(_kbhit())
       {
        m=getch();
        if(m=='w')
         d='w';
         if(m=='s')
         d='s';
         if(m=='d')
         d='d';
         if(m=='a')
         d='a';
       }
        if(d=='w')
                x--;
            else if(d=='s')
                x++;
            else if(d=='d')
                y++;
            else if(d=='a')
                y--;
        
      if(!check_lose(board,x,y))
           {
                cout<<"Looooooser";
                goto end;
             }           

           check_food(board,x,y,score);
            board[x][y]=snake[0];
            
            
            system("cls");
            print_board(board);
             
            board[x][y]=' ';
           
            this_thread::sleep_for(chrono::milliseconds(500));
           
           
        }
   
   end: this_thread::sleep_for(chrono::seconds(2));

}