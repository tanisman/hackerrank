//this is listed as Easy but i wanted to include
//since i love greedy solutions.
//also this is 40p solution.
#include <bits/stdc++.h>

using namespace std;

vector<int> jimOrders(vector<vector<int>> orders) {
    map<int, std::vector<int>> serve_times; //<--- using map (or multimap) is the trick
    vector<int> result;
    for (int i = 0; i < orders.size(); i++)
    {
        int t = orders[i][0] + orders[i][1];
        auto it = serve_times.find(t);
        if (it != serve_times.end())
        {
            it->second.push_back(i + 1);
        }
        else
        {
            serve_times[t] = vector<int>();
            serve_times[t].push_back(i + 1);
        }
    }
    
    for (auto pair : serve_times)
    {
        for (int i = 0; i < pair.second.size(); i++)
        {
            result.push_back(pair.second[i]);
        }
    }
    return result;
}
