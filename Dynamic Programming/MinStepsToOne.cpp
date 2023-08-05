#include<cmath>
#include<climits>

//Dynamic Programming


int countMinStepsToOne(int n,int arr[])
{    
	



	arr[0]=0;
	arr[1]=0;
	arr[2]=1;

	int a,b,c,mini,fini;

	b=INT_MAX;
	c=INT_MAX;

	for(int i=2;i<=n;i++)
	{
	       a=arr[i-1];

		  if(i%2==0)
		  b=arr[i/2];

		  if(i%3==0)
		  c=arr[i/3];

		  mini=min(a,min(b,c));

		  

		  arr[i]=mini+1;

		  b=INT_MAX;
		  c=INT_MAX;


	}

     return arr[n];
}

int countStepsToOne(int n)
{ 
	int* ans=new int[n+1];

	for(int i=0;i<=n;i++)
	ans[i]=-1;


	return countMinStepsToOne(n,ans);

}
