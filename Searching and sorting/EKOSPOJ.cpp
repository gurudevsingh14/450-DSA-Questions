//problem link: https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isPossible(ll a[], ll n, ll m, ll height)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > height)
            sum += a[i] - height;
    }
    if (sum >= m)
        return true;
    else
        return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];

    ll high = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        high = max(high, a[i]);
    }
    
    ll low = 1;
    ll mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (isPossible(a, n, m, mid))//if its possible we are increasing height of blade in order to maximize the height of blade
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    cout << high << "\n";

}