#include <iostream>
#include <stack>
using namespace std;

#define MAX 5

const char* feature_list[MAX] = {
    "engine control",
    "fuel system",
    "ignition",
    "sensor module",
    "logging system"
};

int graph[MAX][MAX] = {0};
int visit[MAX] = {0};   

bool dfs(int start)
{
    stack<pair<int,int>> st;

  
    st.push({start, 0});

    while(!st.empty())
    {
        int node = st.top().first;
        int state = st.top().second;
        st.pop();

        if(state == 0)
        {
            if(visit[node] == 1)
            {
                cout << "cycle presented and one node in it "
                     << feature_list[node] << endl;
                return false;
            }

            if(visit[node] == 2)
                continue;

            visit[node] = 1;

        
            st.push({node, 1});

         
            for(int i = MAX - 1; i >= 0; i--)
            {
                if(graph[node][i] == 1)
                {
                    st.push({i, 0});
                }
            }
        }
        else
        {
            visit[node] = 2;

            cout << "activating feature: "
                 << feature_list[node] << endl;
        }
    }

    return true;
}

int main()
{
    graph[0][1] = 1; // Engine → Fuel
    graph[0][2] = 1; // Engine → Ignition
    graph[1][3] = 1; // Fuel → Sensor
    graph[2][3] = 1; // Ignition → Sensor
    graph[3][4] = 1; // Sensor → Logging

    cout << "starting ECU feature activation\n";

    if(dfs(0))
        cout << "all features enabled successfully\n";
    else
        cout << "activation failed due to cycle\n";

    return 0;
}
