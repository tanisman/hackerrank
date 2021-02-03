#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int k, vector<int> c) {
    int max_flowers_per_friend = ceil(c.size() / (float)k);
    sort(c.begin(), c.end());
    int total = 0;
    int n = c.size();
    int bought = 0;
    for (int i = 0; i < max_flowers_per_friend; i++)
    {
        for (int j = 0; j < k ; j++)
        {
            total += c[n - bought - 1] * (i + 1);
            //cout << "person " << j << endl;
           // cout << "buy flower " << n - bought 
            //    << " for " << (c[n - bought - 1] * (i + 1)) << endl;
            if (++bought >= c.size())
                break;
        }
    }
    return total;
}