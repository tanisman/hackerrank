#include <bits/stdc++.h>

using namespace std;

string morganAndString(string a, string b) {
    int sp_a = 0, sp_b = 0;
    auto min_len = std::min(a.length(), b.length());
    string result = "";
    while(sp_a < a.length() && sp_b < b.length())
    {
        if (a[sp_a] <= b[sp_b])
        {
            result += a[sp_a++];
        }
        else
        {
            result += b[sp_b++];
        }
    }
    while (sp_a < a.length())
        result += a[sp_a++];
    while (sp_b < b.length())
        result += b[sp_b++];

    return result;
}
