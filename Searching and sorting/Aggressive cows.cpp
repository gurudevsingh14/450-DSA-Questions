//problem link: https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;

bool assign(int stall[], int n, int c, int limit)
{
    c--;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (stall[i] - stall[prev] >= limit) {
            c--;
            prev = i;
        }
    }
    if (c <= 0)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int stall[n];
        for (int i = 0; i < n; i++)
        {
            cin >> stall[i];
        }
        sort(stall, stall + n);
        int low = 1;
        int high = stall[n - 1];
        int mid;
        int ans = 0;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (assign(stall, n, c, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}