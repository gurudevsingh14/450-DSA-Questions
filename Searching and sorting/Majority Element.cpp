//problem link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

int majorityElement(int a[], int n)
    {
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
        {
            if(++m[a[i]]>n/2)
            return a[i];
        }
        return -1;
        
    }