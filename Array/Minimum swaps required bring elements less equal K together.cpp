//problem link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0

int minSwap(int *a, int n, int k) {
    int good = 0, bad = 0, min_swap = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
            good++;
    }
    if (good == 0 || good == 1)
        return 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
            bad++;
        if (i - start + 1 == good)
        {
            min_swap = min(min_swap, bad);
            if (a[start] > k)
                bad--;
            start++;
        }
    }
    return min_swap;
}
