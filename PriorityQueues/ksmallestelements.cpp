#include<queue>
#include<vector>


vector<int> kSmallest(int arr[], int n, int k) {
    
    priority_queue<int> pq;

  for(int i=0;i<k;i++)
  {
      pq.push(arr[i]);
  }

  for(int i=k;i<n;i++)
  {
      if(arr[i]<pq.top())
      {pq.push(arr[i]);
      pq.pop();}


  }

  vector<int> v;

  while(!pq.empty())
  {
    v.push_back(pq.top());
    pq.pop();
  }

  return v;

  
}
