int minCostPathDP(int **input, int m, int n) {
   

  int** output=new int*[m];

  for(int i=0;i<m;i++)
  {
	  output[i]=new int[n];

	for(int j=0;j<n;j++)
	output[i][j]=-1;
  }
  
  //Fill the Last Cell
  output[m-1][n-1]=input[m-1][n-1];

  //Fill the Last Row

  for(int j=n-2;j>=0;j--)
  output[m-1][j]=input[m-1][j]+output[m-1][j+1];

  //Fill the last Column

  for(int p=m-2;p>=0;p--)
  output[p][n-1]=input[p][n-1]+output[p+1][n-1];

  //Fill the remaining elements

  for(int a=m-2;a>=0;a--)
  {
  for (int b = n - 2; b >= 0; b--) {
        output[a][b] =
            min(output[a + 1][b], min(output[a][b + 1], output[a + 1][b + 1])) +
            input[a][b];
  }
  }

  return output[0][0];
}

int minCostPath(int **input, int m, int n) {

	

	return minCostPathDP(input, m, n);
}
