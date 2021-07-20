// problem link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {

        unordered_map<int, int>m;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int diff = k - arr[i];

            count += m[diff];
            
            m[arr[i]]++;
        }

        return count;
    }
};