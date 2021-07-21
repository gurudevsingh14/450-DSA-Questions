//problem link: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

class Solution
{
public:
    int trappingWater(int a[], int n)
    {
        int left_max = 0,//left most block with maximum height
        right_max = n - 1,//right most block with maximum height
        left_ptr = 1, //left pointer
        right_ptr = n - 2; //right pointer
        int ans = 0;
        while (left_ptr <= right_ptr)
        {
            if (a[left_max] < a[right_max])
            {
                if (a[left_ptr] < a[left_max])
                {
                    ans += a[left_max] - a[left_ptr];
                }
                else
                    left_max = left_ptr;
                left_ptr++;
            }
            else
            {
                if (a[right_ptr] < a[right_max])
                {
                    ans += a[right_max] - a[right_ptr];
                }
                else
                    right_max = right_ptr;
                right_ptr--;
            }
        }
        return ans;
    }
};