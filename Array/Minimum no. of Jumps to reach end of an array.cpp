//problem link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

class Solution{
  public:
    int minJumps(int a[], int n){

        int travel_end=a[0];
        int travel=a[0];
        int steps=0;

        for(int i=0;i<n-1;i++)
        {
            travel=max(travel,(i+a[i]));

            if(travel_end==i)
            { 
                travel_end=travel;
                steps++;
            }
            
        }

        if(travel_end>=n-1)
            return ++steps;
        else 
            return -1;
        
    }
};