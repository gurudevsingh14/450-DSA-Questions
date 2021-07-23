// problem link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0

bool find3Numbers(int a[], int n, int x)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum == x)
                return 1;
            else if (sum > x)
                k--;
            else
                j++;
        }
    }
    return 0;
}