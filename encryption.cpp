#include <bits/stdc++.h>

using namespace std;

string encryption(string s) {
    string result;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int l = s.length();
    int r = floor(sqrt(l));
    int c = ceil(sqrt(l));
    if (r * c < l)
        r = c;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (i + j * c >= l)
                break;
            result += s[i + j * c];
        }
        result += " ";
    }
    
    return result.erase(result.find_last_not_of(" ") + 1);
}