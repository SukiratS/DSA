void heapSort(int arr[], int n) {
    
    int i=1; int child,parent; int temp;

    while(i<n)
    {
        child=i;
        

        while(child>0)
        {
            parent=(child-1)/2;
            if(arr[child]<arr[parent])
            {
                temp=arr[parent];
                arr[parent]=arr[child];
                arr[child]=temp;
            }
            else
            break;

            child=parent;
        }

        i++;
    }

    int j=n-1; int parentindex=0,childindex,minindex,lc=1,rc=2,temp1;

    while(j>0)
    {
        int ans=arr[j];
        arr[j]=arr[0];
        arr[0]=ans;

        parentindex=0;
        lc=1;
        rc=2;
        minindex=parentindex;

        while (lc < j) {
          

          if (arr[minindex] > arr[lc])
            minindex = lc;

          if (rc < j && arr[minindex] > arr[rc])
            minindex = rc;

          temp1 = arr[minindex];
          arr[minindex] = arr[parentindex];
          arr[parentindex] = temp1;

          if(minindex==parentindex)
          break;

          parentindex = minindex;
          minindex = parentindex;
          lc = 2 * parentindex + 1;
          rc = 2 * parentindex + 2;
        }

        j--;
    }
}
