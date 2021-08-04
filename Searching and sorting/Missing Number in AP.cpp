//problem link: https://practice.geeksforgeeks.org/problems/arithmetic-number/1

int inSequence(int A, int B, int C) {
    if (C == 0) {
        if (A == B)
            return 1;
        else
            return  0;
    }
    else {
        if ((B - A) / C < 0)
            return 0;
        else {
            if ((B - A) % C == 0)
                return 1;
            else
                return 0;
        }
    }
}

//-----------------An another problem---------------------------------------------
//Find the missing number in Arithmetic Progression
//Input: arr[]  = {2, 4, 8, 10, 12, 14}
//Output: 6
//gfg article link: https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/
//problem link: https://www.codingninjas.com/codestudio/problems/missing-number-in-ap_975498?leftPanelTab=0

/*The idea is to go to the middle element. Check if the index of middle element is equal to 
(nth position of middle element in AP) - 1 then the missing element lies lies at right half 
if not then the missing element lies at left half (this idea is similar to 
Find the only repeating element in a sorted array of size n ).  
After breaking out of binary search loop the missing element will lie between high and low. 
We can find the missing element by adding a common difference with element at index high 
or by subtracting a common difference with element at index low.*/

int missingNumber(vector<int> &a, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int diff = (a[n - 1] - a[0]) / n;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if ((a[mid] - a[0]) / diff == mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return a[high] + diff;
}
