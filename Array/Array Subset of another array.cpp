// problem link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int>map;

    for (int i = 0; i < m; i++)
    {
        map[a2[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        map.erase(a1[i]);
    }

    if (map.size() == 0)
        return "Yes";
    else
        return "No";
        
}