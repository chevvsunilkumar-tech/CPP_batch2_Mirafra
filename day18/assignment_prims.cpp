#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class CAN
{
    unordered_map<string, vector<pair<string,int>>> adj;

public:

    void add_edge(string src_ecu, string dst_ecu, int route_cost)
    {
        adj[src_ecu].push_back({dst_ecu, route_cost});
        adj[dst_ecu].push_back({src_ecu, route_cost});
    }

    vector<pair<pair<string,string>,int>> mst_prims(string src_ecu)
    {
        unordered_map<string,bool> visited;
        unordered_map<string,int> dist;
        unordered_map<string,string> parent;

        // Initialize
        for(auto &p : adj)
        {
            visited[p.first] = false;
            dist[p.first] = INT_MAX;
            parent[p.first] = "";
        }

        dist[src_ecu] = 0;

        priority_queue<pair<int,string>, vector<pair<int,string>>,greater<pair<int,string>>> pq;

        pq.push({0, src_ecu});

        while(!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            int weight = current.first;
            string node = current.second;

            if(visited[node])
                continue;

            visited[node] = true;

            for(auto &neighbor : adj[node])
            {
                string next_node = neighbor.first;
                int next_weight = neighbor.second;

                if(!visited[next_node] && dist[next_node] > next_weight)
                {
                    dist[next_node] = next_weight;
                    parent[next_node] = node;
                    pq.push({next_weight, next_node});
                }
            }
        }

        vector<pair<pair<string,string>,int>> result;

        for(auto &p : adj)
        {
            string node = p.first;
            if(node != src_ecu)
                result.push_back({{parent[node], node}, dist[node]});
        }

        return result;
    }
};

int main()
{
    CAN network;

    network.add_edge("engine control", "battery management", 3);
    network.add_edge("engine Control", "dashboard", 4);
    network.add_edge("battery management", "dashboard", 2);
    network.add_edge("battery management", "ADAS camera", 6);
    network.add_edge("dashboard", "ADAS camera", 5);
    network.add_edge("dashboard", "rear parking sensor", 7);
    network.add_edge("ADAS Camera", "infotainment", 4);
    network.add_edge("rear Parking Sensor", "infotainment", 3);

    vector<pair<pair<string,string>,int>> mst = 
        network.mst_prims("Engine Control");

    int total_weight = 0;

    cout << "minimum spanning tree:\n";

    for(auto &edge : mst)
    {
        cout << "{{"<<edge.first.first << ", "<<edge.first.second << "}," << edge.second << " meters"<<"}\n";

        total_weight += edge.second;
    }

    cout << "\ntotal cable cost: " 
         << total_weight << " meters\n";

    return 0;
}
