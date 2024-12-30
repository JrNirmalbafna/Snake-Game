#include<iostream>
#include <cstdlib>
#include <conio.h>
#include<windows.h>

using namespace std;

void setup();
void draw();
void input();
void logic();

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], taily[100]; // To store tail position
int ntail; // Length of snake
bool gameover;
enum edirections{STOP = 0, LEFT, RIGHT, UP, DOWN };
edirections dir;

int main()
{
    setup();

    while (!gameover)
    {
        draw();
        input();
        logic();
        Sleep(10); //To control speed

    }
}
void setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;  //starting position at the centre
    y = height / 2;
    fruitX = rand() % width; //random at width
    fruitY = rand() % height; // random at height
    score = 0; //initail score
    ntail = 0; //Initaial tail length
}

void draw()
{
    system("cls");  //clear screen
    for(int i = 0; i < width + 2; i++)  
    {
        cout<<"_"; // For top wall
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
            else if (i == fruitY && j == fruitX)
            {
            cout << "O"; // Fruit
            }
            else 
            {
                bool print = false;
                
                for(int k = 0; k < ntail; k++)
                {
                    if (tailX[k] == j && taily[k] == i)
                    {
                        cout << "<"; // tail
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " "; // empty space
                }
            }
            if (j == width - 1)
            {
                cout << "||"; // right wall
            }
            
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "_"; // Bottom wall
    }
    cout << endl;
    cout << "Score: "<< score << endl; // display score


}

void input()
{
    if(_kbhit()) // for keybord input
    {
        switch (_getch())
        {
        case 'a': dir = LEFT; break;
        case 'd': dir = RIGHT; break;
        case 'w': dir = UP; break;
        case 's': dir = DOWN; break;
        case 'x': gameover = true; break; // game exit

        }
    }
}

void logic()
{
    int prevX = tailX[0];
    int prevY = taily[0];
    int prev2x, prev2y;
    tailX[0] = x;
    taily[0] = y;

    for(int i = 0; i < ntail; i++)
    {
        prev2x = tailX[i];
        prev2y = taily[i];
        tailX[i] = prevX;
        taily[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }

    switch (dir)
    {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;

    default: break;
    }

    if (x >=width) 
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 1;
    }

    if(y >=height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }

    for (int i = 0; i < ntail; i++)
    {
        if(tailX[i] == x && taily[i] == y)
        {
            gameover = true;
        }
    }

    if(x == fruitX && y == fruitY)
    {
        score += 10; // increase score
        fruitX = rand() % width; // new fruit on width 
        fruitY = rand() % height; // new fruit on height
        ntail++; // increse length of snake
    }
}