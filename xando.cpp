#include<iostream>
#include <cctype>
#include <utility>
#include<thread>
#include<chrono>

using namespace std;
char tablica[3][3]={
{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}
};
char original[3][3]={
{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}
};
void printboard(char (&t)[3][3])
{
    cout<<"-------"<<endl;
    for(auto& x:t)
    {

        cout<<"|";

        for(auto y:x)
            cout<<y<<"|";
    cout<<endl<<"-------"<<endl;

    }


}

void put(char k,int x, int y,char tablica[3][3])
    {
        tablica[x][y]=k;

    }
bool ifwin(char t[3][3],char c)
{

    if(t[0][1]==c&&t[0][0]==c&&t[0][2]==c)
    return true;
    else if(t[1][1]==c&&t[1][0]==c&&t[1][2]==c)
    return true;
    else if(t[2][1]==c&&t[2][0]==c&&t[2][2]==c)
    return true;
    else if(t[0][1]==c&&t[1][1]==c&&t[2][1]==c)
    return true;
    else if(t[0][2]==c&&t[1][2]==c&&t[2][2]==c)
    return true;
     else if(t[0][0]==c&&t[1][0]==c&&t[2][0]==c)
    return true;
    else if(t[0][0]==c&&t[1][1]==c&&t[2][2]==c)
    return true;
    else if(t[0][2]==c&&t[1][1]==c&&t[2][0]==c)
    return true;

    else
    return false;



}
bool can_move(int x, int y,char tablica[3][3])
 {
    if(x>2 || y>2 || x<0 || y<0 )
        return false;


     return true;
 }
pair<int, int> available_place(char tablica[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (tablica[x][y] == ' ')
                return {x, y};
        }
    }

    return {-1, -1};
}
int main()
{
    char k;
    string s;
    int x=0,y=0,n=0;
    printboard(tablica);
    cout<<"kto chce zacząć X lub O";
    cin>>s;
    if(s.length()>1)
       return 1;
    k=s[0];
    k=(char)toupper(k);

    if(k!='X'&& k!='O')
      return 1;
    // select

    char m;
    

    while(n!=9)
    {
        auto place = available_place(tablica);
        x = place.first;
        y = place.second;
        while (true)
    {
        
        tablica[x][y]='#';
        system("cls");
        printboard(tablica);

        cin>>m;
        if(m=='n')
        {
            if(original[x][y]==' ')
              break;
            else
            {
                cout<<"you canot go there";
                 tablica[x][y]=original[x][y];
                x = place.first;
                y = place.second;
            this_thread::sleep_for(chrono::seconds(2));
            }
              
        }
        tablica[x][y]=original[x][y];
        if(m=='w')

        {

            x--;
            if(can_move(x,y,tablica)){
                tablica[x][y]=' ';
            }
            else
            {
               x++;

            }

        }
        else if(m=='s')
        {

            x++;
            if(can_move(x,y,tablica)){tablica[x][y]=' ';}
            else{
               x--;
            }

        }
        else if(m=='d')
        {

            y++;
            if(can_move(x,y,tablica)==1){tablica[x][y]=' ';}
            else{
                y--;
            }

        }
        else if(m=='a')
        {

            y--;
            if(can_move(x,y,tablica)==1){ tablica[x][y]=' ';}
            else
            {
               y++;
            }

        }


    }
        //cout<<"napisz wiersz (1-3) i kolumnę (1-3) oddzielone spacją:";
        //cin>>x>>y;
         put(k,x,y,tablica);
         put(k,x,y,original);
        system("cls");
        printboard(tablica);
         if(n>=4)
        if(ifwin(tablica,k))
        {
            cout<<k<<" IS THE WINNER";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }


        if(k=='X')
        k='O';
        else
        k='X';
        n++;
        if(n < 9)
        {
            do
            {
                y++;
                if(y > 2)
                {
                    y=0;
                    x++;
                    if(x > 2)
                        x=0;
                }
            } while(!can_move(x,y,tablica));
        }

    }








}
