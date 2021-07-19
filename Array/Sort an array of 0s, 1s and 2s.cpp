class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int left=0;
        int right=n-1;
        for(int i=0;i<=right;i++)
        {
            if(a[i]==0)
            {
                swap(a[i],a[left]);
                left++;
            }
            else if(a[i]==2)
            {
                swap(a[i],a[right]);
                right--;
                i--;
            }
        }
    }
};