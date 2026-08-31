#include<iostream>
#include<windows.h>
using namespace std;
int main()
{ SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while(true)
    {
        system("cls");
        int c;
    cout<<"press 1 to open labirynt"<<endl;
    cout<<"press 2 to open X i O"<<endl;
    cout<<"press 3 to open wąż"<<endl;
    cout<<"to exit 4"<<endl;
    cin>>c;
    if(c==1)
    {
        system("cls");
        system("labirynt.exe");
    }
    
    else if(c==2)
     {
        system("cls");
    system("xando.exe");
     }
    else if(c==3)
     {
        system("cls");
    system("snake.exe");
     }
    else if(c==4)
    break;
    }
    


}