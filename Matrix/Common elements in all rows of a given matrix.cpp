#include<bits/stdc++.h>
using namespace std;

void commomelements(vector<vector<int>>& matrix, int r, int c)
{
    unordered_map<int, int>m;

    for (int i = 0; i < c; i++)
        m[matrix[0][i]] = 1;

    for (int i = 1; i < r; i++)
        for (int j = 0; j < c; j++) {

            if (m[matrix[i][j]] == i) {
                m[matrix[i][j]] = i + 1;

                if (i == r - 1)
                    cout << matrix[i][j] << " ";
            }
        }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>>matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    commomelements(matrix, r, c);
    return 0;
}
