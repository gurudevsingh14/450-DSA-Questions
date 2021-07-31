//problem link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

vector<int> find(int a[], int n , int x )
{
    vector<int>ans(2, -1);
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (a[low] == x)
        ans[0] = low;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (a[high] == x)
        ans[1] = high;
    return ans;
}