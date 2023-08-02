
#include<bits/stdc++.h>
using namespace std;
int global[19][19];
int arr[19][19];


bool isPossible(int r,int c)
{
	if(global[r][c]==1)
	return true;
	else
	return false;
}


void pathhelper(int row,int column,int n)
{
	

	if(row==n-1&&column==n-1)
	{

		arr[row][column]=1;

		for(int a=0;a<n;a++)
		{
		for(int b=0;b<n;b++)
		cout<<arr[a][b]<<" ";
		}

		cout<<endl;

		return;

	
	}

	if(row==n||row==-1||column==n||column==-1||global[row][column]==0||arr[row][column]==1)
	return;
               
        
                arr[row][column]=1;
				pathhelper(row-1,column,n);
				pathhelper(row+1,column,n);
				pathhelper(row,column-1,n);
				pathhelper(row,column+1,n);

			   arr[row][column]=0;	
}

int main() {

	int N;
	cin>>N;

	
	

	int i,j;

	for( i=0;i<N;i++)
	{
	for(j=0;j<N;j++)
	{
		cin>>global[i][j];
	}
	}

   for(int p=0;p<19;p++)
   {
	for(int q=0;q<19;q++)
	arr[p][q]=0;
   }



     pathhelper(0,0,N);
	
}




