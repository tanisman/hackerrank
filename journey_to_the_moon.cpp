//timeouts on test cases 8, 9 and 11
//will updated later
#include <bits/stdc++.h>

using namespace std;

struct vertex 
{
    int id; 
    vector<int> neighbors; 
};

void DFS(int v, vector<vertex> g, vector<bool>& visited, int& nodes)
{
    visited[v] = true;
    nodes++;
    for (int u : g[v].neighbors)
    {
        if (!visited[u])
        {
            DFS(u, g, visited, nodes);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) { //the idea is build disconnected graph
														  //with adding edges between astronauts
														  //from same country
														  //and count connected components
    vector<vertex> graph;   
    for (int i = 0; i < n; i++)
    {
        vertex v;
        v.id = i;
        graph.push_back(v);
    }
    
    
    for (auto& pair : astronaut)
    {
        auto& v = graph[pair[0]];
        auto& u = graph[pair[1]];
        v.neighbors.push_back(u.id);
        u.neighbors.push_back(v.id);
    }
    
    vector<bool> visited(n, false);
    vector<int> components;
    int count = 0;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
        {
            int nodes = 0;
            DFS(v, graph, visited, nodes);
            count++;
            components.push_back(nodes);
        }
    }
    
    if (count < 2)
    {
        return 0;
    }
    else
    {
        int sum = 0;
        
        for (int i = 0; i < components.size() - 1; i++)
        {
            for (int j = i + 1; j < components.size(); j++)
            {
                sum += components[i] * components[j];
            }
        }
        return sum;
    }
}
