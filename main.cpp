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
    cout<<"\033[31mnaciśnij 1, aby otworzyć labirynt\033[0m"<<endl;
    cout<<"\033[34mnaciśnij 2, aby otworzyć X i O\033[0m"<<endl;
    cout<<"\033[32mnaciśnij 3, aby otworzyć wąż\033[0m"<<endl;
    cout<<"\033[35mnaciśnij 4, aby wyjść\033[0m"<<endl;
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