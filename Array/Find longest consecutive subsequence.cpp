// problem link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int n)
    {
        map<int, int> map;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (map[arr[i] - 1] >= 1)
                continue;
            else
            {
                int j = arr[i];
                int count = 0;
                while (map[j] >= 1)
                {
                    j++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};