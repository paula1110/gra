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
    cout<<"naciśnij 1, aby otworzyć labirynt"<<endl;
    cout<<"naciśnij 2, aby otworzyć X i O"<<endl;
    cout<<"naciśnij 3, aby otworzyć wąż"<<endl;
    cout<<"naciśnij 4, aby wyjść"<<endl;
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