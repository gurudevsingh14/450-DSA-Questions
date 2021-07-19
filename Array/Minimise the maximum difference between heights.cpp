//problem link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        sort(a,a+n);

        int ans=a[n-1]-a[0];

        int shortest=a[0]+k;
        int longest=a[n-1]-k;
        int minimize,maximize;

        for(int i=0;i<n-1;i++)
        {
            minimize=min(shortest,a[i+1]-k);
            maximize=max(longest,a[i]+k);

            if(minimize<0)
            continue;

            ans=min(ans,maximize-minimize);
        }
        
        return ans;
    }
};