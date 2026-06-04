#include <iostream>
#include<chrono> // duration
#include<thread> // sleep
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

int main(){

    int pr=1,pc=0;
    char x;
    char (*actual)[10]=maz1;
    while(true)
    {
        system("cls");
        printmaz(maz1);
        cin>>x;
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
                cout<<" you cant go there";
                this_thread::sleep_for(chrono::seconds(5));
                continue;
            }
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
                cout<<" you cant go there";
                this_thread::sleep_for(chrono::seconds(5));
                continue;
            }
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
                cout<<" you cant go there";
                this_thread::sleep_for(chrono::seconds(5));
                continue;
            }
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
                cout<<" you cant go there";
                this_thread::sleep_for(chrono::seconds(5));
                continue;
            }
        }

    }

}
