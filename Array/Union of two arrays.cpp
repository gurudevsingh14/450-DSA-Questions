//problem link : https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
        map<int,bool>map;
        for(int i=0;i<n;i++)
        map[a[i]]=true;
        for(int i=0;i<m;i++)
        map[b[i]]=true;
        
        return map.size();
    }
};