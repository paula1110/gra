#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>
#include<thread>
#include<conio.h>



using namespace std;
struct food{
    int x;
    int y;
};
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

bool check_lose(char board[10][20],int x,int y,vector<food>snake)
{
    if(board[x][y]=='#')
     return false;
    for(int i=1;i<snake.size();i++) 
    {
        if(snake[i].x==snake[0].x && snake[i].y==snake[0].y )
         return false;
    }

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

void new_food(char board[10][20])
{
   // srand(time(0));
    food result;
    
    while(true)
    {
    result.x = rand() % 8+1;
    result.y= rand() % 18+1;
    if(board[result.x][result.y]==' ')
    {
        board[result.x][result.y]='*';
        break;
    }
    
    }
    
}
void check_food(char board[10][20],vector<food>&v,food t)
{
    if(board[v[0].x][v[0].y]=='*')
    {
        v.push_back(t);
        new_food(board);
    }
    
    
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
    food old_tail;
    //vector<char> snake ={'O'};
    vector<food> snake;
    snake.push_back({1,1});
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
       // where is the tail
       old_tail=snake.back();
       //--------------------------
       for(int i=snake.size()-1;i>0;i--)
       {
        snake[i]=snake[i-1];
       }
        if(d=='w')
               snake[0].x--;
            else if(d=='s')
                snake[0].x++;
            else if(d=='d')
                snake[0].y++;
            else if(d=='a')
                snake[0].y--;
        
      if(!check_lose(board,snake[0].x,snake[0].y,snake))
           {
                cout<<"Looooooser";
                goto end;
             }           

           check_food(board,snake,old_tail);
            //board[x][y]=snake[0];
            for(auto x: snake)
            {
                board[x.x][x.y]='o';
            }
            
            
            system("cls");
            print_board(board);
             
            for(auto x: snake)
            {
                board[x.x][x.y]=' ';
            }
           
            this_thread::sleep_for(chrono::milliseconds(500));
           
           
        }
   
   end: this_thread::sleep_for(chrono::seconds(2));

}