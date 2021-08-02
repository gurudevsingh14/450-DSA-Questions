//problem link: https://practice.geeksforgeeks.org/problems/stickler-theif/0

int FindMaxSum(int a[], int n)
{
    int excl = 0;
    int incl = a[0];
    int new_exc = 0;
    for (int i = 1; i < n; i++)
    {
        new_exc = (incl > excl) ? incl : excl;

        incl = excl + a[i];
        excl = new_exc;
    }
    return (incl > excl) ? incl : excl;
}