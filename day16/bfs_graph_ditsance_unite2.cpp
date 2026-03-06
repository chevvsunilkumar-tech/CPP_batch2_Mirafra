#include <iostream>
#include <vector>
#include <queue>
#include<climits>
#include<algorithm>
using namespace std;

void bfs(int start,int dest, vector<vector<int>>& adj)
{ // start =0
    int V = adj.size();

    vector<bool> visited(V, false);

    queue<int> q; 

   
    visited[start] = true;
    q.push(start);
    
  vector<int>p(V,-1);
  

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " "; 

        
        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; 
                q.push(neighbor); 
                  p[neighbor] =node;     
             }
        }
        }
   
    
 vector<int>path;
 
 for(int i=dest;i!=-1;)
 {
 path.push_back(i);
 i=p[i];
 
 }
 reverse(path.begin(),path.end());
 cout<<"path\n";
 for(int x:path)
 cout<<x<<" ";
 cout<<endl;
 
cout<<"ditance :"<<path.size()-1<<endl;
 
 
}
/*
void bfs(int start, vector<vector<int>>& adj)
{ // start =0
    int V = adj.size();

    vector<bool> visited(V, false);

    queue<int> q; 

   
    visited[start] = true;
    q.push(start);
    
    vector<int>dist(V,INT_MAX);
    dist[start]=0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " "; 

        
        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; 
                q.push(neighbor); 
                int d=dist[node]+1;
                if(dist[neighbor]>d)
                dist[neighbor]=d;
            }
        }
        }
   
    
   cout<<"\ndistance array\n";
   for(const auto &x:dist)
   cout<<x<<" ";
   cout<<endl;
}

*/
int main()
{
    int V = 5;
    vector<vector<string>> adj(V);

    adj[0] = {"school", 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2,3};

    cout << "BFS Traversal: ";
    bfs(0,4, adj);

    return 0;
}
