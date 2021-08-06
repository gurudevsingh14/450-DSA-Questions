//problem link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

long long merge(long long a[], long long l, long long mid, long long h)
{
    long long count = 0;
    long long n1 = mid - l + 1;
    long long n2 = h - mid;
    long long a1[n1];
    long long a2[n2];
    for (long long i = 0; i < n1; i++)
        a1[i] = a[l + i];
    for (long long i = 0; i < n2; i++)
        a2[i] = a[mid + 1 + i];
    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            a[k++] = a1[i++];
        else {
            count += n1 - i;
            a[k++] = a2[j++];
        }
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
    return count;
}
long long int mergesort(long long a[], long long l, long long h)
{
    long long int count = 0;
    if (l < h)
    {
        long long mid = (l + h) / 2;
        count += mergesort(a, l, mid);
        count += mergesort(a, mid + 1, h);
        count += merge(a, l, mid, h);
    }
    return count;
}
// Function to count inversions in the array.
long long int inversionCount(long long A[], long long n)
{
    return mergesort(A, 0, n - 1);
}