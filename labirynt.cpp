#include <iostream>
#include<chrono> // duration
#include<thread> // sleep
#include<conio.h>
using namespace std;
void printmaz(char Maze[10][10]){
    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<Maze[i][j];
        }
        cout<< endl;
    }
}
char maz1[10][10]={
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'P', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '.', '.', '#', '#', '.', 'E'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};
char maz2[10][10]=
{
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'P', '.', '.', '.', '#', '.', '.', '.', '#', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '.', '#', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', 'E'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};
char maz3[10][10]=
{
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'P', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', 'E'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}

};
bool check(int r,int c,char maz[10][10])
{
    if(maz[r][c]=='#')
        return false;
    else
        return true;
}
bool checkwin(int r,int c,char maz[10][10])
{
    if(maz[r][c]=='E')
        return true;
    else
        return false;
}
int main(){

    int pr=1,pc=0,l=1;
    char x;
    char (*actual)[10]=maz1;
     printmaz(actual);
    while(true)
    {

        
       
        if(_kbhit())
        {
            x=getch();        
        
        
        
        if(x=='w')
        {
            
            pr--;
            if(check(pr,pc,actual)== 1)
            {

                swap(actual[pr+1][pc],actual[pr][pc]);
            }
            else
            {
                pr++;
                cout<<"\033[31m nie możesz tam iść\033[0m";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
             printmaz(actual);
                continue;
            }
            if(checkwin(pr,pc-1,actual)==1)
        {
            
            pr=1;

            pc=0;
            l++;
            if(l==2)
            {
                actual=maz2;
                cout<<"\033[34mwygrałeś, przechodzisz na następny poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
               
            else if(l==3)
            {
                actual=maz3;
                cout<<"\033[34mwygrałeś, przechodzisz na ostatni poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
                
            else
                break;


        }

system("cls");
            printmaz(actual);
        }
        else if(x=='s')
        {
            
            pr++;
             if(check(pr,pc,actual)== 1)
            {
                swap(actual[pr-1][pc],actual[pr][pc]);
            }
            else
            {pr--;
                cout<<"\033[31m nie możesz tam iść\033[0m";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
            printmaz(actual);
                continue;
            }
            if(checkwin(pr,pc-1,actual)==1)
        {
            
            pr=1;

            pc=0;
            l++;
            if(l==2)
            {
                actual=maz2;
                cout<<"\033[34mwygrałeś, przechodzisz na następny poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
               
            else if(l==3)
            {
                actual=maz3;
                cout<<"\033[34mwygrałeś, przechodzisz na ostatni poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
                
            else
                break;

       
        }

 system("cls");
            printmaz(actual);
        }
        else if(x=='a')
        {
            pc--;
             if(check(pr,pc,actual)== 1)
            {
                swap(actual[pr][pc+1],actual[pr][pc]);
            }
            else
            {
                pc++;
                cout<<"\033[31m nie możesz tam iść\033[0m";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
            printmaz(actual);
                continue;
            }
            if(checkwin(pr,pc-1,actual)==1)
        {
            
            pr=1;

            pc=0;
            l++;
            if(l==2)
            {
                actual=maz2;
                cout<<"\033[34mwygrałeś, przechodzisz na następny poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
               
            else if(l==3)
            {
                actual=maz3;
                cout<<"\033[34mwygrałeś, przechodzisz na ostatni poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
                
            else
                break;

       
        }
system("cls");
            printmaz(actual);

        }
        else if(x=='d')
        {
            pc++;
             if(check(pr,pc,actual)== 1)
            {
                swap(actual[pr][pc-1],actual[pr][pc]);
            }
            else
            {pc--;
                cout<<"\033[31m nie możesz tam iść\033[0m";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
            printmaz(actual);
                continue;
            }
             if(checkwin(pr,pc-1,actual)==1)
        {
            
            pr=1;

            pc=0;
            l++;
            if(l==2)
            {
                actual=maz2;
                cout<<"\033[34mwygrałeś, przechodzisz na następny poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
               
            else if(l==3)
            {
                actual=maz3;
                cout<<"\033[34mwygrałeś, przechodzisz na ostatni poziom\033[0m";
            this_thread::sleep_for(chrono::seconds(2));
            }
                
            else
                break;


        }
system("cls");
            printmaz(actual);
        }

    }}
    system("cls");
    cout<<"\033[32mgratulacje, wygrales\033[0m";
    this_thread::sleep_for(chrono::seconds(2));
}
