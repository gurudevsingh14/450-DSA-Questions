//problem link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *a, int n)
    {
        long long max_eh = a[0], //maximum product ending till current index
            min_eh = a[0],       //minimum product ending till current index
            max_so_far = a[0];   //maximum product obtained so far(result variable)

        for (int i = 1; i < n; i++)
        {
            long long num = a[i];
            if (a[i] == 0)
            {
                max_so_far = max(max_so_far, num);
                max_eh = 1;
                min_eh = 1;
                continue;
            }
            long long temp = max_eh;

            max_eh = max(num, max(num * max_eh, min_eh * num));
            max_so_far = max(max_so_far, max_eh);
            min_eh = min(num, min(num * min_eh, num * temp));
        }

        return max_so_far;
    }
};