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
    while(true)
    {

        system("cls");
        printmaz(actual);
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
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
             if(checkwin(pr+1,pc,actual)==1)
        {
            cout<<"you win";
            //this_thread::sleep_for(chrono::seconds(2));
            pr=1;
            pc=0;
            l++;
            if(l==2)
               actual=maz2;
            else
                actual=maz3;


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
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
             if(checkwin(pr-1,pc,actual)==1)
        {
            cout<<"you win";
            pr=1;
            pc=0;
            l++;
            if(l==2)
               actual=maz2;
            else
                actual=maz3;


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
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
             if(checkwin(pr,pc+1,actual)==1)
        {
            pr=1;
            pc=0;
            cout<<"you win";
            l++;
            if(l==2)
               actual=maz2;
            else
                actual=maz3;


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
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
             if(checkwin(pr,pc-1,actual)==1)
        {
            cout<<"you win";
            pr=1;

            pc=0;
            l++;
            if(l==2)
               actual=maz2;
            else if(l==3)
                actual=maz3;
            else
                break;


        }

        }

    }
    system("cls");
    cout<<"gratulacje, wygrales";

}
