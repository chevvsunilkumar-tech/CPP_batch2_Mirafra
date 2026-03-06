#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
//iusing pair<int,int> =vertix;
class graph
{
    vector<vector<pair<int,int>>> adj_l;
    int V;

public:
    graph(int size) : V(size)
    {
        adj_l.resize(V);
    }

    void add_edge(int u, int v, int w)
    {
        adj_l[u].push_back({v, w});
        adj_l[v].push_back({u, w});
    }

    void shortest_dist(int src)
    {
       
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        vector<bool>visited(V,false);

        q.push({0, src});
        

        while(!q.empty())
        {
            auto cur = q.top();
            q.pop(); 

            int d = cur.first;
            int node = cur.second;

           
            for(auto &it : adj_l[node])
            {    
                int n_node = it.first;
                int n_dist = it.second;
                 if(visited[n_node])
                 continue;

                if(dist[n_node] > d + n_dist)
                {
                    dist[n_node] = d + n_dist;
                    q.push({dist[n_node], n_node});
                }
            }
            visited[node]=true;
        }

        
        cout << "shortest ditance from nodes" << src << ":\n";
        for(int i=0;i<V;i++)
        {
        cout<<src<<" to "<<i<<": shortest distance :"<<dist[i]<<endl;
        }
    }
    
    
 void print_graph()
{
    cout << "graph representation:\n";
    for(int u = 0; u < V; u++)
    {
        cout << u << " -> ";
        for(auto &[v, w] : adj_l[u])
        {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }
}
    
    
};

int main()
{
    graph g(5);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 1);
    g.add_edge(3, 4, 3);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 3, 5);
    g.print_graph();

    g.shortest_dist(0);

    return 0;
}
