//problem link: https://practice.geeksforgeeks.org/problems/count-squares3649/1

int countSquares(int N) {
    if (N == 0 || N == 1)
        return 0;
    int count = 0;
    int res = 1;
    for (int i = 1; res < N; i++)
    {
        res = i * i;
        count++;
    }
    return count - 1;
}