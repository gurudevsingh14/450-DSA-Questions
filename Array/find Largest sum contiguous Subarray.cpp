//problem link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution{
    public:
    int maxSubarraySum(int a[], int n){
        
        int max_so_far=INT_MIN;
        int curr=0;
        
        for(int i=0;i<n;i++)
        {
            curr+=a[i];
            
            max_so_far=max(curr,max_so_far);
            
            if(curr<0)
            curr=0;
        }
        return max_so_far;
    }
};