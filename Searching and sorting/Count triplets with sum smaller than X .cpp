//problem link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

long long countTriplets(long long a[], int n, long long sum)
{
    long long count = 0;
    sort(a, a + n);
    int x = 0, y, z;
    for (int x = 0; x < n - 2; x++)
    {
        y = x + 1;
        z = n - 1;
        while (y < z)
        {
            int s = a[x] + a[y] + a[z];
            if (s < sum) {
                count += z - y;
                y++;
            }
            else z--;
        }
    }
    return count;
}