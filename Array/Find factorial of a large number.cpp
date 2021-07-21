// problem link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0

class Solution
{
public:
    vector<int> factorial(int n)
    {
        vector<int> ans;
        ans.push_back(1);

        int carry = 0;
        int product = 1;

        for (int i = 2; i <= n; i++)
        {
            int j = 0;
            while (j < ans.size())
            {
                product = i * ans[j] + carry;

                ans[j] = product % 10;
                carry = product / 10;

                j++;
            }

            while (carry > 0)
            {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};