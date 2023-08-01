#include<iostream>
using namespace std;

 int board[11][11];
  vector<vector<int>> pq;


  bool isPossible(int row,int col,int n)
{
        for(int a=row-1;a>=0;a--)
        {
            if(board[a][col]==1)
            return false;
        }

        for(int a=row-1,b=col-1;a>=0&&b>=0;a--,b--)
        {
            if(board[a][b]==1)
            return false;
        }

        for(int a=row-1,b=col+1;a>=0&&b<n;a--,b++)
        {
            if(board[a][b]==1)
            return false;
        }

        return true;
}

void placenQueenshelper(int n,int row)
{
    if(row==n)
    {    
        vector<int> temp;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
       }

       pq.push_back(temp);



    }



    for(int j=0;j<n;j++)
    {
        if(isPossible(row,j,n))
        {
            board[row][j]=1;
            placenQueenshelper(n,row+1);
            board[row][j]=0;
        }
        else
           board[row][j]=0;


    }
}




vector<vector<int>> nQueens(int n)
{
     

     
     
      placenQueenshelper(n,0);

    return pq;
}
