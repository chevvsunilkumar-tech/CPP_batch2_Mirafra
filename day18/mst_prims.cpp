#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>

using namespace std;


vector<pair<pair<int,int>, int>> calculatePrimsMST(
        int n,
        vector<pair<pair<int,int>, int>> &g)
{
   
    unordered_map<int, list<pair<int,int>>> adj;

    for (auto edge : g)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // Undirected
    }

    // Step 2: Initialize structures
    vector<int> key(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Min Heap → {key, vertex}
    priority_queue<  pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>
    > pq;

    // Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    // Step 3: Prim’s Algorithm
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;

            if (!visited[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Step 4: Store result
    vector<pair<pair<int,int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}


// Driver Code
int main()
{
    int n = 5;

    vector<pair<pair<int,int>, int>> edges = {
        {{1,2}, 2},
        {{1,3}, 3},
        {{2,3}, 1},
        {{2,4}, 4},
        {{3,4}, 5},
        {{4,5}, 7}
    };

    auto mst = calculatePrimsMST(n, edges);

    cout << "Edges in MST:\n";
    for (auto edge : mst)
    {
        cout << edge.first.first << " - "
             << edge.first.second << "  weight: "
             << edge.second << endl;
    }

    return 0;
}
