//problem link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0

ll findSubarray(vector<ll> a, int n ) {
    unordered_map<ll, ll>m;
    ll sum = 0;
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        m[sum]++;
        if (m[sum] >= 2)
            count += m[sum] - 1;
    }
    return count + m[0];

}