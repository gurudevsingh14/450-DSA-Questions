//problem link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {   
        int n=arr.size();
        int left=0;
        int right=n-1;
        for(int i=0;i<=right;i++)
        {
            if(arr[i]<a)
            {
                swap(arr[i],arr[left]);
                left++;
            }
            else if(arr[i]>b)
            {
                swap(arr[i],arr[right]);
                right--;
                i--;
            }
        }
    }
};