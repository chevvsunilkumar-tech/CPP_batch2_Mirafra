#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int countComponents(vector<vector<int>>& adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    int count = 0;

    for(int i = 0; i < V; i++) // V=5
    {
        if(!visited[i])
        {
            cout << "Component " << count + 1 << ": ";
            dfs(i, adj, visited);
            cout << endl;
            count++;
        }
    }

    return count;
}

int main()
{
    int V = 7;
    vector<vector<int>> adj(V);

    // Component 1
    adj[0].push_back(1); // 0-1
    adj[1].push_back(0); // 1-0

    adj[1].push_back(2); //1-2
    adj[2].push_back(1);

    // Component 2
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    adj[5].push_back(6);
    

    int components = countComponents(adj);

    cout << "\nTotal Connected Components: "
         << components << endl;

    return 0;
}
