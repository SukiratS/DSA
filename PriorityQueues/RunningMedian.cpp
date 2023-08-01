#include<queue>

int buyTicket(int *arr, int n, int k) {

   queue<int> q1;
   priority_queue<int> pq;

   for(int i=0;i<n;i++)
   {
       q1.push(i);
       pq.push(arr[i]);
   }  
  
  int c=0,temp;

   while(!pq.empty())
   {
       temp=q1.front();

       if(arr[temp]==pq.top())
       {
         if (temp == k) {
           c++;
           break;
         } else {
          
           q1.pop();
           pq.pop();
           c++;
         }
       }

       else{
             q1.pop();
             q1.push(temp);
       }
   }

   return c;
}
