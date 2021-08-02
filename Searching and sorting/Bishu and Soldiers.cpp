//problem link: https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include<bits/stdc++.h>
using namespace std;

void round(int soliders[], int power[] , int n , int q)
{
    sort(soliders, soliders + n);
    int prefix[n];
    prefix[0] = soliders[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = soliders[i] + prefix[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (soliders[mid] <= power[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << low << " ";
        cout << prefix[low - 1] << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    int soliders[n];
    for (int i = 0; i < n; i++)
        cin >> soliders[i];
    int q;
    cin >> q;
    int power[q];
    for (int i = 0; i < q; i++)
        cin >> power[i];
    round(soliders, power, n, q);
    return 0;
}