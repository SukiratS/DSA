#include <vector>
#include<climits>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
      
      

      if(isEmpty())
      return INT_MIN;


      int ans=pq[0];
      pq[0]=pq[pq.size()-1];
      pq.pop_back();

      int parentindex=0;

    int lc=1;
    int rc=2;   int temp;

  while(lc<pq.size())
  {

  
        lc=2*parentindex+1;
      rc=2*parentindex+2;

   
   
   
     

      int minindex=parentindex;

  
      
          if(pq[minindex]>pq[lc])
          {
              minindex=lc;
          }

          if (rc < pq.size() && pq[minindex] > pq[rc]) {
            minindex = rc;
          }

          if (minindex == parentindex)
            break;

          temp = pq[parentindex];
          pq[parentindex] = pq[minindex];
          pq[minindex] = temp;

          parentindex = minindex;
  }

  return ans;
    }
};
