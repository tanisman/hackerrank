//this is listed as Easy but i wanted to include
//since i love greedy solutions. (+presort)
#include <bits/stdc++.h>

using namespace std;

int luckBalance(int k, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end(), [](vector<int> a, vector<int> b)
    {
       return a[0] > b[0]; 
    });
    
    int luck = 0;
    for(auto& contest : contests)
    {
        if (contest[1] == 0)
        {
            luck += contest[0];
        }
        else 
        {
           if (k > 0)
           {
               k--;
               luck += contest[0];
           }
           else 
           {
               luck -= contest[0];
           }
        }
    }
    cout <<endl;
    return luck;
}
