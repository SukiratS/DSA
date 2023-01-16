int  subsetSumToK(int input[], int n, int output[][50],int k){
    if(n==0){
        output[0][0]=0;
        return 1;
    }
  
    int out1[1000][50];
    int ans=subsetSumToK(input+1,n-1,out1,k);//not included
    
    int newoutput[1000][50];
    
    int ans1=subsetSumToK(input+1,n-1,newoutput,k-input[0]);
    
    int i;
  
    for( i=0; i < ans; i++){
        for(int j = 0; j <= out1[i][j]; j++){
          output[i][j]=out1[i][j];
        }
    }
    
    
    for(int i=0;i<ans1;i++){
        output[i+ans][0]=newoutput[i][0]+1;
        output[i+ans][1]=input[0];

       for(int j=0;j<newoutput[i][0];j++){
           output[i+ans][j+2]=newoutput[i][j+1];
       }   


    } 
    
    return (ans+ans1);   
}
