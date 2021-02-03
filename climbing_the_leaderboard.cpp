#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int m, n, tmp;
    cin >> n;
    map<unsigned int, int, greater<unsigned int>> a;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.emplace(tmp, i);
    }
    
    int x = 0;
    for (auto& it : a)
    {
        it.second = x++;
    }
    
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        auto ub = a.lower_bound(tmp);
        if (ub == a.end())
            cout << a.size() + 1 << endl;
        else
        {
            cout << 
                ub->second + 1 << endl;
        }
        a.erase(ub, a.end()); //decreasing search space (removing this also would pass)
    }
    return 0;
}
