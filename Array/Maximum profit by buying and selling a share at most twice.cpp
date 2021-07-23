// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n, 0);

        int max_sp = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            max_sp = max(max_sp, prices[i]);
            dp[i] = max(dp[i + 1], max_sp - prices[i]);
        }

        int min_cp = prices[0];
        for (int i = 1; i < n; i++)
        {
            min_cp = min(min_cp, prices[i]);
            dp[i] = max(dp[i - 1], dp[i] + prices[i] - min_cp);
        }
        
        return dp[n - 1];
    }
};