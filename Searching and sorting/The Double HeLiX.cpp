//problem link: https://www.spoj.com/problems/ANARC05B/

#include<bits/stdc++.h>
using namespace std;

void solve(int a[], int n, int b[], int m)
{
    int i = 0, j = 0;
    int prefix1 = 0, prefix2 = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            prefix1 += a[i++];
        else if (b[j] < a[i])
            prefix2 += b[j++];
        else {
            ans = ans + max(prefix1, prefix2) + a[i];
            prefix1 = 0;
            prefix2 = 0;
            i++; j++;
        }
    }
    while (i < n) {
        prefix1 += a[i++];
    }
    while (j < m) {
        prefix2 += b[j++];
    }
    ans += max(prefix1, prefix2);
    cout << ans << "\n";
}


int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        solve(a, n, b, m);
    }
}