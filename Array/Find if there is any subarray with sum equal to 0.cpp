// problem link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

class Solution {
public:
    bool subArrayExists(int a[], int n)
    {
        unordered_map<int, int>m;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];

            m[sum]++;

            if (m[sum] >= 2 || sum == 0)
                return true;
        }

        return false;
    }
};