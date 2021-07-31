//problem link: https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1#

pair<long long, long long> getMinMax(long long a[], int n) {
    long long min;
    long long max;
    if (n % 2 == 0) {
        if (a[0] < a[1]) {
            min = a[0];
            max = a[1];
        } else {
            min = a[1];
            max = a[0];
        }
    }
    else {
        min = a[0];
        max = a[0];
    }
    for (int i = (n % 2 == 0) ? 2 : 1; i < n - 1; i += 2)
    {
        if (a[i] > a[i + 1]) {
            if (a[i] > max)
                max = a[i];
            if (a[i + 1] < min)
                min = a[i + 1];
        } else {
            if (a[i + 1] > max)
                max = a[i + 1];
            if (a[i] < min)
                min = a[i];
        }
    }
    pair<long long, long long>ans = {min, max};
    return ans;
}