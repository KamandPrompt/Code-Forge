#include <bits/stdc++.h>
using namespace std;

// ---> BACKTRACKING ALGORITHM APPLICATION =>THE SUDOKU SOLVER

// Backtracking is a problem-solving approach that involves recursively constructing a solution step by step,
//  while discarding any partial solutions that violate the problem's constraints at any given point in the process 
// (considering time as the elapsed duration at each level of the search tree).

#define N 9 //consider only 9x9 sudoku

// function to check whether [row,col] cell is valid to be filled with k
bool is_safe(int row,int col,int k,int grid[N][N])
{
    for (int i = 0; i < 9; i++){
        if (grid[i][col] == k)//if any other rows have value k then return false
            {return false;}

        if (grid[row][i] == k)
            {return false;}//if any other columns have value k then return false

        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)//if any other cell in common 3x3 matrix have value k then return false
        {return false;}
    }
    // else if all above condition never comes true then return true as that (row,col) cell is safe to be filled with k
    return true;
}

bool SolveSudoku(int grid[N][N])  
{ 
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            //for each cell of sudoku
            if(grid[row][col]==0) // if that cell is not filled yet
            {
                for (int k = 1; k <= N; k++)//then try to fill it with all possible values and
                {
                    if(is_safe(row,col,k,grid)){
                        grid[row][col]=k;
                        if(SolveSudoku(grid)){return true;}// then check whether constraints are meeting for next upcoming steps or not
                        else{grid[row][col]=0;}// if no valid solution exist then backtrack one step i.e., make that cell unfilled
                    }
                }
                // if no valid solution exist for any value between 1 - 9 for a cell, 
                // then return false so that previous recursive call can backtrack and try other value for previous cells
                return false;
            }
        }   
    }
    return true;   
}

//Function to print each cell of the 9x9 Sudoku.
void printGrid (int grid[N][N]) 
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
		
    cout<<"Enter all the 81 value of sudoku(write 0 for the not given values)"<<endl;
    int grid[N][N];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
    
    if (SolveSudoku(grid) == true)  
    {
        printGrid(grid);
    }
    else
    {
        cout << "No valid solution exists"<<endl;
    }
	
	return 0;
}
