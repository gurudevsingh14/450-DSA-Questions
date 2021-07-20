// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();

        int minprice = INT_MAX;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            minprice = min(minprice, a[i]);//minimum price

            ans = max(ans, a[i] - minprice);//maximum difference between selling and cost price (profit)
        }
        
        if (ans > 0)
            return ans;
        else
            return 0;
    }
};