#include<iostream>
#include <cstdlib>
#include<windows.h>

using namespace std;

bool gameover;

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], taily[100];     // Last stage of game
int ntail;

enum edirections{STOP = 0, LEFT, RIGHT, UP, DOWN };
edirections dir;

void arrangement()
{
    gameover = false;
    dir = STOP;
    x = width / 2;  //starting position at the centre
    y = height / 2;
    fruitX = rand() % width; //random at width
    fruitY = rand() % height; // random at height
    score = 0; // At the start score is zero
}

void board()
{
    system("cls");  //clear screen
    for(int i = 0; i < width + 2; i++)  
    {
        cout<<"_";
    }
    cout<<endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0)
            {
                cout<<"||";  // left wall
            }
            if(i == y && j == x)    //Determining the position of head
            {
                cout<<"*";
            }
        }
    }
    cout<<endl;

}