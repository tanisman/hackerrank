//does not pass test case 11 and 12
//this solution got 48.95/50 tho.
#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    vector<int> dist(n, 1);
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dist[i] = dist[i - 1] + 1;
        }
        else 
        {
            dist[i] = 1;
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && dist[i] <= dist[i + 1])
        {
            dist[i] = dist[i + 1] + 1;
        }
    }
    
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        sum += dist[i];
    }
    
    return sum;
}