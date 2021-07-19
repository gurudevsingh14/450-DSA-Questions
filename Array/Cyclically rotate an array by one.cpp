//problem link : https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void rotate(int a[], int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        swap(a[i],temp);
    }
    a[0]=temp;
}