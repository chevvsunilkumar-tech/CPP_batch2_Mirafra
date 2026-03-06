#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
#include <string>

using namespace std;

struct place
{
    string name;
    int dist;
    place(string n, int d) : name(n), dist(d) {}
};

struct cmp
{
    bool operator()(const place &a, const place &b)
    {
        return a.dist > b.dist; 
    }
};

class graph
{
    unordered_map<string, list<place>> adj_l;

public:
    void add_edge(const string &u, const string &v, int w)
    {
        adj_l[u].push_back(place(v, w));
        adj_l[v].push_back(place(u, w));
    }

    void shortest_dist(const string &src)
    {
        unordered_map<string, int> dist;
        unordered_map<string, bool> visited;

        for (auto &p : adj_l)
            dist[p.first] = INT_MAX;

        dist[src] = 0;

        priority_queue<place, vector<place>, cmp> q;
        q.push(place(src, 0));

        while (!q.empty())
        {
            place cur = q.top();
            q.pop();

            string node = cur.name;
            if (visited[node])
                continue;
            visited[node] = true;

            for (auto &neighbor : adj_l[node])
            {
                if (!visited[neighbor.name] && dist[neighbor.name] > dist[node] + neighbor.dist)
                {
                    dist[neighbor.name] = dist[node] + neighbor.dist;
                    q.push(place(neighbor.name, dist[neighbor.name]));
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (auto &p : dist)
        {
            if (p.second == INT_MAX)
                cout << src << " to " << p.first << ": INF\n";
            else
                cout << src << " to " << p.first << ": " << p.second << endl;
        }
    }

    void print_graph()
    {
        cout << "Graph representation:\n";
        for (auto &p : adj_l)
        {
            cout << p.first << " -> ";
            for (auto &neighbor : p.second)
                cout << "(" << neighbor.name << "," << neighbor.dist << ") ";
            cout << endl;
        }
    }
};

int main()
{
    graph g;

    g.add_edge("A", "B", 4);
    g.add_edge("A", "C", 1);
    g.add_edge("B", "C", 2);
    g.add_edge("B", "D", 1);
    g.add_edge("C", "D", 5);
    g.add_edge("D", "E", 3);

    g.print_graph();
    g.shortest_dist("A");

    return 0;
}
