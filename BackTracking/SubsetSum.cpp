#include<bits/stdc++.h>
using namespace std;

int subsetcount(int arr[],int k,int N,int i,int sum)
{
    if(i==N)
    {
        if(sum==k)
        return 1;
        else
        return 0;
    }
        
        int opt1=0,opt2=0;
     opt1+=subsetcount(arr,k,N,i+1,sum+arr[i]);
     opt2+=subsetcount(arr,k,N,i+1,sum);

    return (opt1+opt2);
}


int main(){

    int N,k;
    
    
    int T;
    cin>>T;

    while (T > 0) {
      cin >> N >> k;
      int *arr = new int[N];

      for(int i=0;i<N;i++)
      {
          cin>>arr[i];
      }

      int c = subsetcount(arr, k,N,0,0);

      cout << c << endl;

      T--;
    }
    return 0;
}

