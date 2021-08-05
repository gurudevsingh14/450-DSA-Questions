//problem link: https://www.spoj.com/problems/PRATA/

#include<bits/stdc++.h>
using namespace std;
bool isPossible(int rank[], int n, int prata, int mid)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int time = rank[i];
        int j = 2;
        while (time <= mid)
        {
            time += j * rank[i];
            count++;
            j++;
        }
    }
    if (count >= prata)
        return true;
    else
        return false;
}
void solve()
{
    int prata;
    cin >> prata;
    int l;
    cin >> l;
    int rank[l];
    for (int i = 0; i < l; i++)
        cin >> rank[i];

    int low = 1;
    int high = INT_MAX;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (isPossible(rank, l, prata, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}