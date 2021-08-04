//problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

int allocate(int a[], int n, int m, int limit)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > limit)return 0;
        if (a[i] + sum > limit) {
            student++;
            sum = a[i];
        }
        else {
            sum += a[i];
        }
    }
    if (student <= m) {
        return 1;
    }
    else {
        return 0;
    }
}
//Function to find minimum number of pages.
int findPages(int a[], int n, int m)//m is the number of students
{
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += a[i];
    }
    int low = 1;
    int mid;
    int ans = INT_MAX;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (allocate(a, n, m, mid)) {
            ans = min(mid, ans);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;

}