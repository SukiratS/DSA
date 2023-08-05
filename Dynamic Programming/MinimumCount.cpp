#include<cmath>
#include<climits>

//Dynamic Programming

int minCountCalculate(int n,int ans[])
{
    int i=1;

	int power=1;

	while(power<=n)
	{
		  i++;
		power=i*i;
	}

   int c=i-1;  int min1,mini=INT_MAX;

   for(int j=1;j<=c;j++)
   {     
	    int s=n-(j*j);
         min1=ans[s];
		 min1++;

		 if(mini>min1)
		 mini=min1;
   }

   return mini;
}

int minCountfinal(int n,int ans[])
{
     ans[0]=0;
	 ans[1]=1;
	

	 if(ans[n]!=-1)
	 return ans[n];

	 for(int i=2;i<=n;i++)
	 {
		ans[i]=minCountCalculate(i,ans);
	 }
     

	 return ans[n];

}









int minCount(int n)
{
	int* ans=new int[n+1];

	for(int j=0;j<=n;j++)
	ans[j]=-1;

	return minCountfinal(n,ans);
}
