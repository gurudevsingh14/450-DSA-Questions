//problem link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge(int a1[], int a2[], int n1, int n2) {
    int i, j, gap = n1 + n2;
    for (gap = nextGap(gap); gap >= 1; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n1; i++)
        {
            if (a1[i] > a1[i + gap])
                swap(a1[i], a1[gap + i]);
        }
        for (j = (i + gap) > n1 ? (i + gap) - n1 : 0; j < n2 && i < n1; j++, i++)
        {
            if (a1[i] > a2[j])
                swap(a1[i], a2[j]);
        }
        if (j < n2) {
            for (j = 0; j + gap < n2; j++) {
                if (a2[j] > a2[j + gap])
                    swap(a2[j], a2[j + gap]);
            }
        }
    }
}