#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int pairs(int k, vector<int> arr) {
    int ctr = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] - arr[i] > k)
            {
                break;
            }
            else if (arr[j] - arr[i] == k)
            {
                ctr++;
            }
        }
    }
    return ctr;
}