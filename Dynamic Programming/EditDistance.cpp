int editDistance(string s1, string s2)
{
    int m=s1.size();
    int n=s2.size();

    int** output=new int*[m+1];

    for(int i=0;i<=m;i++)
    {
    output[i]=new int[n+1];

    for(int j=0;j<=n;j++)
    output[i][j]=-1;

    }

   

     for(int j=0;j<=n;j++)
     output[0][j]=j;

     for(int i=0;i<=m;i++)
     output[i][0]=i;

     for(int i=1;i<=m;i++)
     {
     for(int j=1;j<=n;j++)
     {
      
        if(s1[m-i]==s2[n-j])
        output[i][j]=output[i-1][j-1];

     else
     {
      int a=output[i-1][j];
      int b=output[i][j-1];
      int c=output[i-1][j-1];

      a++;b++;c++;
     output[i][j]=min(a,min(b,c));

     }}}

     return output[m][n];
}
