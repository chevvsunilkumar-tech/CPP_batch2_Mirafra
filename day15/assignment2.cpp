#include <iostream>
#include <unordered_map>
#include <list>
#include <limits>
#include <optional>
#include <string>

using namespace std;

template<typename N, typename D>
class graph
{
    unordered_map<N, list<pair<N,D>>> adj_list;

public:
    void add_edge(N sr, N dst, D weight, bool directed = true)
    {
        adj_list[sr].push_back({dst, weight});
    }

    void display_graph()
    {
        for (auto &key : adj_list)
        {
            cout << key.first << " -> ";
            for (auto &[destination, distance] : key.second)
            {
                cout << "(" << destination << ", " << distance << "km) ";
            }
            cout << endl;
        }
    }

    optional<pair<N,D>> find_shortest_neighbour(N node)
    {
        if (adj_list.find(node) == adj_list.end())
            return nullopt;

        auto &lst = adj_list[node];
        if (lst.empty())
            return nullopt;

        D shortest_dist = numeric_limits<D>::max();
        N nearest_node;

        for (auto &[dest, distance] : lst)
        {
            if (distance < shortest_dist)
            {
                shortest_dist = distance;
                nearest_node = dest;
            }
        }
        return make_pair(nearest_node, shortest_dist);
    }
};

int main()
{
    graph<string, float> hyderabad_police;

    
    hyderabad_police.add_edge("nampally ps", "secunderabad ps", 3.2f);
    hyderabad_police.add_edge("nampally ps", "balanagar ps", 4.5f); 

    hyderabad_police.add_edge("secunderabad ps", "begumpet ps", 2.5f);
    hyderabad_police.add_edge("secunderabad ps", "ameerpet ps", 3.0f); 

    hyderabad_police.add_edge("begumpet ps", "ameerpet ps", 2.2f);
    hyderabad_police.add_edge("ameerpet ps", "s r nagar ps", 1.5f);

    hyderabad_police.add_edge("s r nagar ps", "kukatpally ps", 2.0f);
    hyderabad_police.add_edge("s r nagar ps", "balanagar ps", 2.8f); 

    hyderabad_police.add_edge("kukatpally ps", "balanagar ps", 1.8f);
    hyderabad_police.add_edge("balanagar ps", "nampally ps", 4.0f); 

    cout << "directed hyderabad police stations graph:\n";
    hyderabad_police.display_graph();

    cout << "\nshortest neighbour from 'nampally ps':\n";
    auto result = hyderabad_police.find_shortest_neighbour("nampally ps");
    if (result)
        cout << "next station: " << result->first
             << " at " << result->second << " km\n";
    else
        cout << "no neighbour found\n";

    cout << "\nshortest neighbour from 's r nagar ps':\n";
    auto result2 = hyderabad_police.find_shortest_neighbour("s r nagar ps");
    if (result2)
        cout << "next station: " << result2->first
             << " at " << result2->second << " km\n";
    else
        cout << "no neighbour found\n";

    return 0;
}

