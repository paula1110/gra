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
bool is_valid_food_position(char board[10][20], vector<food> snake, int x, int y)
{
    if (board[x][y] == '#') return false;
    if (board[x][y] != ' ') return false;

    for (int i = 0; i < snake.size(); i++)
    {
        if (snake[i].x == x && snake[i].y == y)
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

void new_food(char board[10][20],vector<food>snake)
{
   // srand(time(0));
    
    
    while(true)
    {
    int x = rand() % 8+1;
    int y= rand() % 18+1;
    if(is_valid_food_position(board,snake,x,y))
    {
        board[x][y]='*';
        break;
    }
    
    }
    
}
void check_food(char board[10][20],vector<food>&v,food t,int&score)
{
    if(board[v[0].x][v[0].y]=='*')
    {
        v.push_back(t);
        new_food(board,v);
        score++;
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
    char d;
    food old_tail;
    
    vector<food> snake;
    snake.push_back({1,1});
    new_food(board,snake);
    while(true)
    {
        board[1][1]='O';
    print_board(board);

    cin>>d;
    if(d!='d' && d!='s')
    {
        cout<<"\033[33mkliknij d, aby przesunąć się w prawo lub s, aby przesunąć się w dół\033[0m";
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
    }
    else
    {
        board[1][1]=' ';
        break;
    }
    ;
    }
   
    while (true)
    {
    // cout<<score;   
       if(_kbhit())
       {
        m=getch();
        if(m=='w' && d!='s')
         d='w';
         if(m=='s' && d!='w')
         d='s';
         if(m=='d' && d!='a')
         d='d';
         if(m=='a' && d!='d')
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
                cout<<"\033[33mTWÓJ WYNIK TO "<<score<<"\033[0m";
                goto end;
             }           

           check_food(board,snake,old_tail,score);
            // draw
            
            for(int i=0;i<snake.size();i++)
            {
                if(i==0)
                board[snake[i].x][snake[i].y]='O';
                else
                board[snake[i].x][snake[i].y]='o';
            }
            
            
            system("cls");
            print_board(board);
             // clear
            for(auto x: snake)
            {
                board[x.x][x.y]=' ';
            }
           
            this_thread::sleep_for(chrono::milliseconds(350));
           
           
        }
   
   end: this_thread::sleep_for(chrono::seconds(2));

}