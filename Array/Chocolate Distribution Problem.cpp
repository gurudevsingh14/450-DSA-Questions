//problem link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0

long long findMinDiff(vector<long long> a, long long n, long long m) {
    
    sort(a.begin(), a.end());
    int start = 0;
    long long ans = INT_MAX;
 
    for (int i = 0; i < n; i++)
    {
        if ((i - start + 1) == m)
        {
            ans = min(ans, a[i] - a[start]);
            start++;
        }
    }
    
    return ans;
}