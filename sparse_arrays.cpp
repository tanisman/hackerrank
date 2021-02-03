#include <bits/stdc++.h>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> freq;
    for (auto q : queries)
    {
        freq.emplace(q, 0);
    }
    for (auto s : strings)
    {
        auto it = freq.find(s);
        if (it != freq.end())
        {
            it->second += 1;
        }
    }
    vector<int> result;
    for (auto q : queries)
    {
        result.push_back(freq[q]);
    }
    return result;
}
