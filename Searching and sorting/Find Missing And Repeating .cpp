//problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

int *findTwoElement(int *a, int n) {
    int ans[2];
    for (int i = 0; i < n; i++) {
        if (a[a[i] - 1] > 0)
            a[a[i] - 1] = -a[a[i] - 1];
        else {
            ans[0] = a[a[i] - 1];
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] > 0) {
            ans[1] = i;
            break;
        }
    return ans;
}