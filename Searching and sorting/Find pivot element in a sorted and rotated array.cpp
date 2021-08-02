#include<bits/stdc++.h>
using namespace std;

int pivot(int a[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < a[high])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return a[low];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << pivot(a, n);
    return 0;
}