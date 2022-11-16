/* Author: Raisa Methila
Task: Write a program that can stream in a maze
and set up the array then take in directions to see if they can traverse the custom maze,
can evaluate multiple direction lists using the semicolon symbol that must be used at the end of 
each direction in the input.*/

#include <iostream>
using namespace std;

int main(){
    int row = 0;
    int col = 1;
    int maze[10][10]; 
    {
        for (int row= 0; row < 10; row++){
            for (int col= 0; col < 10; col ++){
                cin >> maze[row][col];
            }
        }
    }

    int r_row, r_col, l_row, l_col;
    cin>> r_row>>r_col>>l_row>>l_col;

    char junk;
    cin >> junk;

    char x;
    while(cin >> x)
    {
        if(x != ';')
        {
            if ( x =='D' && maze[row+1][col] == 0)
                row++;
            else if ( x == 'U' && maze[row-1][col] == 0)
                row--;
            else if ( x == 'R' && maze[row][col+1] == 0)
                col++;
            else if ( x == 'L' && maze[row][col-1] == 0)
                col--;
        }
        else
        {
            if (row == l_row && col== l_col)
                cout<<"You got out of the maze."<<endl;
            else
                cout<<"You are stuck in the maze."<<endl;
            row = r_row, col = r_col;
        }
    }
    return 0;
}