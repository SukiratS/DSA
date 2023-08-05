#include<bits/stdc++.h>
#include<cmath>
using namespace std;

//Dynamic Programming;

const long MOD = 1000000007;

long countNoOfWays(int n,long arr[])
{  

    if(n==0)
    return 1;

    if(n<0)
    return 0;
   

    arr[0]=1;
    arr[1]=1;
    arr[2]=2;

    for(int i=3;i<=n;i++)
    {
      arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%MOD;
    }

    return arr[n];

}

long countWays(int n)
{
    long* arr=new long[n+1];

    for(int j=0;j<=n;j++)
    arr[j]=-1;

   long ans= countNoOfWays(n,arr);

 

   return ans;

}

int main()
{
    int t,n;

    cin>>t;

    while (t > 0) {
      cin >> n;

      cout << countWays(n) << endl;
      t--;
    }
}
