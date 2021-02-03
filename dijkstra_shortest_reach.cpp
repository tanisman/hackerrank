//does not pass test case 7
//i checked discussion a bit, since test case 7 is too big (35 MB)
//loading from iostream wastes a lot of time
//but maybe adding heap to find min dist. vertex
//may amortize some runtime for test case 7 
#include <bits/stdc++.h>

using namespace std;

int minimumDistanceVertex(int n, map<int, float>& distances, map<int, bool>& included)
{
    float min = std::numeric_limits<float>::infinity();
    int min_vertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!included[i] && distances[i] <= min)
        {
            min = distances[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void addEdge(map<int, vector<pair<int, int>>>& edges, int s, int d, int w)
{
    auto it = edges.find(s);
    if (it == edges.end())
    {
        edges[s] = vector<pair<int, int>>();
    }
    edges[s].push_back(make_pair(d, w));
    //cout << "add edge (" << s << ", " << d << ") w=" << w << endl;
}

vector<int> shortestReach(int n, vector<vector<int>> edges_vec, int s) {
    map<int, float> distances;
    map<int, bool> included;
    map<int, vector<pair<int, int>>> edges;
    
    for (auto& edge : edges_vec)
    {
        addEdge(edges, edge[0] - 1, edge[1] - 1, edge[2]);
        addEdge(edges, edge[1] - 1, edge[0] - 1, edge[2]);
    }
    
    for (int i = 0; i < n; i++)
    {
        distances[i] = std::numeric_limits<float>::infinity();
        included[i] = false;
    }
    distances[s - 1] = 0;
        
    for (int i = 0; i < n - 1; i++)
    {
        int u = minimumDistanceVertex(n, distances, included);
        included[u] = true;
        
        for (int v = 0; v < n; v++)
        {
            if (!included[v])
            {
                auto& edge_list = edges[u];
                float min_weight = std::numeric_limits<float>::infinity();
                for (int e = 0; e < edge_list.size(); e++)
                {
                    if (edge_list[e].first == v)
                    {
                        float w = edge_list[e].second;
                        if (w < min_weight) 
                        {
                          min_weight = w;
                        }
                    }
                }
                
                if (distances[u] + min_weight < distances[v])
                {
                    distances[v] = distances[u] + min_weight;
                    //cout << "better path " << u + 1 << "->" << v + 1 << " of value=" << distances[v] << endl;
                }
            }
        }
    }
    vector<int> result;
    for (auto pair : distances)
    {
        if (pair.first != s - 1)
        {
            if (pair.second == std::numeric_limits<float>::infinity())
                pair.second = -1;
            result.push_back(pair.second);
        }
    }
    return result;
}