#include<bits/stdc++.h>
using namespace std;
#define N 9

int grid[N][N];


bool findemptyLocation(int grid[][N],int &row,int &col)
{
    for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
    {
        if(grid[i][j]==0)
        {
            row=i;
            col=j;
            return true;
        }
    }
    }

    return false;

}

bool isSaferow(int grid[][N], int row, int num) {
    for (int j = 0; j < N; j++) {
        if (grid[row][j] == num)
            return false;
    }
    return true;
}

bool isSafecolumn(int grid[][N], int col, int num) {
    for (int p = 0; p < N; p++) {
        if (grid[p][col] == num)
            return false;
    }
    return true;
}

bool isSafeGrid(int grid[][N], int row, int col, int num) {
    int rowfactor = row - (row % 3);
    int colfactor = col - (col % 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[rowfactor + i][colfactor + j] == num)
                return false;
        }
    }
    return true;
}

bool isSafe(int grid[][N],int row,int col,int num)
{
      if(isSaferow(grid, row, num) && isSafecolumn(grid, col, num) && isSafeGrid(grid, row, col, num))
        return true;
      else
        return false;
}


bool solveSudoku(int grid[][N]) {
    int row, col;
    if (!findemptyLocation(grid, row, col))
        return true;

    for (int i = 1; i <= 9; i++) {
        if (isSafe(grid, row, col, i)) {
            grid[row][col] = i;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    
  

   for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

  if(solveSudoku(grid))
 cout<<"true";
  else
cout<<"false";
  
  return 0;
}
