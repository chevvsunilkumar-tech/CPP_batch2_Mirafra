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
    void add_edge(N sr, N dst, D weight, bool directed = false)
    {
        adj_list[sr].push_back({dst, weight});
        if (!directed)
            adj_list[dst].push_back({sr, weight});
    }

    void display_graph()
    {
        for (auto &key : adj_list)
        {
            cout << key.first << " -> ";
            for (auto &[destination, distance] : key.second)
            {
                cout << "(" << destination << "," << distance << ") ";
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
    // School, Bunk, Colony, Park, Hospital, Mall
    graph<string, float> city_graph;

    city_graph.add_edge("school", "bunk", 1.2f);
    city_graph.add_edge("school", "colony", 3.5f);
    city_graph.add_edge("bunk", "park", 2.0f);
    city_graph.add_edge("colony", "mall", 4.1f);
    city_graph.add_edge("park", "hospital", 3.2f);
    city_graph.add_edge("mall", "hospital", 1.8f);
    city_graph.add_edge("bunk", "mall", 2.5f);

    cout << "city graph:\n";
    city_graph.display_graph();

    cout << "\nShortest neighbour of 'bunk':\n";
    auto result = city_graph.find_shortest_neighbour("bunk");

    if (result)
        cout << "node: " << result->first
             << " distance: " << result->second << " km\n";
    else
        cout << "no neighbour found\n";
        
        cout<<"_________________________________________________________\n";
        
        
   cout << "\nshortest neighbour of 'school':\n";
      auto res = city_graph.find_shortest_neighbour("school");
    if (res.has_value())
    {
     pair<string,float> p = res.value();
      cout << "Node: " << p.first << " Distance: " << p.second << endl;
     }
    else
        cout << "no neighbour found\n";

    return 0;
}
