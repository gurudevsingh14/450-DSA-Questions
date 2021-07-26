// problem link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n2 < n1) return MedianOfArrays(nums2, nums1);
    int l1, l2, r1, r2;
    int median = (n1 + n2 + 1) / 2;
    int low = 0;
    int high = n1;
    int cut1, cut2;
    while (low <= high)
    {
        cut1 = (low + high) / 2;
        cut2 = (median - cut1);
        l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
        r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2 == 0) {
                double ans = max(l1, l2) + min(r1, r2);
                ans /= 2.0;
                return ans;
            }
            else
                return (double)max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else
            low = cut1 + 1;
    }
    return 0.0;
}
