#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<bool>& recStack)
{
    visited[node] = true; //node =0
    recStack[node] = true;

    for(int neighbor : adj[node]) // n=1
    {
        if(!visited[neighbor])
        {
            if(dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if(recStack[neighbor]) //call stack
        {
            return true;   // Cycle found
        }
    }

    recStack[node] = false;  // Backtrack
    return false;
}

bool detectCycle(vector<vector<int>>& adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, adj, visited, recStack)) //i =0
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 4;
    vector<vector<int>> adj(V);
   // directed graph
    adj[0].push_back(1);  // 0 -1 -2-0
    adj[1].push_back(2);
    adj[2].push_back(0);   // Creates cycle
   adj[2].push_back(3);

    if(detectCycle(adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
