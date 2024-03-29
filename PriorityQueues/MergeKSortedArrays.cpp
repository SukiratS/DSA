#include<vector>
#include<queue>



vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
  
    vector<int> v1;
      priority_queue<int,vector<int>,greater<int>> pq;

      for(int i=0;i<input.size();i++)
      {
      for(int j=0;j<input[i]->size();j++)
         pq.push(input[i]->at(j));

      }

      while(!pq.empty())
      {
          v1.push_back(pq.top());
          pq.pop();
      }

    return v1;

  }
