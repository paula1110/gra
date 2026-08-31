#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<pair<int,int>> snake;
    snake.push_back({1,1});//0
    snake .push_back({1,2});//1
    cout<<snake[0].second;

}