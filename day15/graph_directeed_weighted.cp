#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

template<typename T>
class directed_weighted_graph
{
    int V;                     // number of vertices
    T INF;                     // infinity value
    vector<vector<T>> adj_m;   // adjacency matrix

public:

    directed_weighted_graph(int size)
        : V(size), INF(numeric_limits<T>::max())
    {
        adj_m.resize(V, vector<T>(V, INF));
    }

    void add_edge(int s, int d, T w)
    {
        // directed graph
        if (s >= 0 && s < V && d >= 0 && d < V)
            adj_m[s][d] = w;
    }

    void print_graph()
    {
        for (auto &row : adj_m)
        {
            for (auto &val : row)
                if(val==INF)
                cout<<setw(10)<<"INF";
                else
                cout << setw(10) << val;
            cout << endl;
        }
    }
};

int main()
{
    directed_weighted_graph<float> obj(5);

    cout << "Empty graph\n";
    obj.print_graph();

    cout << endl;

    obj.add_edge(1, 2, 12.33);
    obj.add_edge(2, 4, 23.2);
    obj.add_edge(2, 3, 33.222);
    obj.add_edge(3, 4, 90.11);

    cout << "After adding edges\n";
    obj.print_graph();

    return 0;
}

