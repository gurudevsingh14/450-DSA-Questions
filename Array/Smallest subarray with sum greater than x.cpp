// problem link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0

class Solution {
public:

    int sb(int a[], int n, int x)
    {
        int ans = INT_MAX;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum > x)
            {
                ans = min(ans, i - start + 1);
                while (sum > x) {
                    sum -= a[start];
                    ans = min(ans, i - start + 1);
                    start++;
                }
            }
        }
        return ans;
    }
};