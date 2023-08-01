
#include<vector>
#include<climits>
class PriorityQueue {
    
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
      
      pq.push_back(element);

      int childindex=pq.size()-1; int parentindex; int temp;

      while(childindex>0)
      {
          parentindex=(childindex-1)/2;

          if(pq[childindex]>pq[parentindex])
          {
              temp=pq[parentindex];
              pq[parentindex]=pq[childindex];
              pq[childindex]=temp;
          }
          else
          {
              break;
          }

          childindex=parentindex;
      }
    }

    int getMax() {
         
         if(isEmpty())
         return INT_MIN;
         return pq[0];
    }

    int removeMax() {
        
        if(isEmpty())
        return INT_MIN;

        int temp;

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int parentindex=0;

        int maxindex;
        int lc=1;
        int rc=2;

        while(lc<pq.size())
        {
            maxindex=parentindex;

            if(pq[maxindex]<pq[rc])
            {
                maxindex=rc;
            }

            if(rc<pq.size()&& pq[maxindex]<pq[lc])
            maxindex=lc;

            temp=pq[parentindex];
            pq[parentindex]=pq[maxindex];
            pq[maxindex]=temp;

            if(maxindex==parentindex)
            break;

            parentindex=maxindex;

            lc=2*parentindex+1;
            rc=2*parentindex+2;



            

        }

        return ans;


    }

    int getSize() { 
       return pq.size();
    }

    bool isEmpty() {
       return pq.size()==0;
    }
};
