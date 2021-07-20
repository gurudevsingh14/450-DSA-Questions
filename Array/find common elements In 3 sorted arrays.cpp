// problem link: https://practice.geeksforgeeks.org/problems/common-elements1132/1

class Solution
{
public:
    vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
    {
        vector<int>ans;
        int i = 0, j = 0, k = 0, prev = 0;

        while (i < n1 && j < n2 && k < n3)
        {

            if (a[i] == c[k] && a[i] == b[j]) {

                if (a[i] != prev) {//if the element is not duplicate
                    ans.push_back(a[i]);
                    prev = a[i];
                }

                i++; j++; k++;
            }
            else if (a[i] < b[j] && a[i] < c[k])
                i++;
            else if (b[j] < c[k])
                j++;
            else
                k++;

        }

        return ans;
    }

};