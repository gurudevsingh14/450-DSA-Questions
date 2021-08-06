#include<bits/stdc++.h>
using namespace std;

void merge(long long a[], long long l, long long mid, long long h)
{
    long long maxele = 0;
    for (int i = l; i <= h; i++)
        maxele = max(maxele, a[i]);
    maxele++;
    long long i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h)
    {
        int ele1 = a[i] % maxele;
        int ele2 = a[j] % maxele;
        if (ele1 > ele2) {
            a[k++] += ele2 * maxele;
            j++;
        }
        else {
            a[k++] += ele1 * maxele;
            i++;
        }
    }
    while (i <= mid) {
        long long el = a[i] % maxele;
        a[k] += (el * maxele);
        i++;
        k++;
    }

    while (j <= h) {
        long long el = a[j] % maxele;
        a[k] += (el * maxele);
        j++;
        k++;
    }
    for (int i = l; i <= h; i++)
        a[i] /= maxele;

}
void mergesort(long long a[], long long l, long long h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main()
{

    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, 0, n - 1) ;

    for (long long i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}