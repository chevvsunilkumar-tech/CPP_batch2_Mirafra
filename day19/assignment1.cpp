#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Disjoint_Set {
    vector<int> parent, rank;
public:
    Disjoint_Set(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_by_rank(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Graph {
    int V;
    vector<pair<int, pair<int,int>>> edges; 

public:
    Graph(int V) {
        this->V = V;
    }

   
    void addEdge(int u, int v, int cost) {
        edges.push_back({cost, {u, v}});
    }

    void kruskal_mst() {
        sort(edges.begin(), edges.end());

        Disjoint_Set ds(V);
        int totalcost = 0;

        cout << "Eedges in MST:\n";

        for(auto edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if(ds.find(u) != ds.find(v)) {
                ds.union_by_rank(u, v);
                cout << u << " - " << v << " : " << cost << " Lakhs\n";
                totalcost += cost;
            }
        }

        cout << "total Minimum cost cable: " << totalcost << " Lakhs\n";
    }
};

int main() {

    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(2,5,2);
    g.addEdge(2,4,4);
    g.addEdge(3,4,3);
    g.addEdge(5,4,3);

    g.kruskal_mst();

    return 0;
}
