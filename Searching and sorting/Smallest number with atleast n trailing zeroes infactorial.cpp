//problem link: https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1

//function to find number of trailing digits in a given number
int CountTrailingZeros(int n)
{
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5)
    {
        count += n / i;
    }
    return count;
}
//function to find smallest number whose factorial contains at least n trailing zeroes.
int findNum(int n)
{
    int low = 5;
    int high = INT_MAX;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (CountTrailingZeros(mid) >= n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}