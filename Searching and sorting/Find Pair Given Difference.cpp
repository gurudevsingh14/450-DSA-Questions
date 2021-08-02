//problem link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

bool findPair(int arr[], int n, int diff){
    sort(arr,arr+n);
    int i=0,j=1;
    while(j<n&&i<n)
    {   
        
        if(i!=j&&abs(arr[j]-arr[i])==diff)
            return true;
            
        else if(abs(arr[j]-arr[i])<diff)
            j++;
        else
            i++;
    }
    return false;
}