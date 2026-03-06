#include <iostream>
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


int visit[MAX]={0};


bool dfs(int node)
{
    
    if(visit[node] == 1)
    {
        cout <<" Cycle presented and one of nnode in it "
             << feature_list[node] << endl;
        return false;
    }

    
    if(visit[node] == 2)
        return true;

    visit[node] = 1;  

    
    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i] == 1)
        {
            if(!dfs(i))
                return false;   
        }
    }

    visit[node] = 2;  

    cout << "Activating Feature: "
         << feature_list[node] << endl;

    return true;
}

int main()
{
   
    graph[0][1] = 1; // Engine → Fuel
    graph[0][2] = 1; // Engine → Ignition
    graph[1][3] = 1; // Fuel → Sensor
    graph[2][3] = 1; // Ignition → Sensor
    graph[3][4] = 1; // Sensor → Logging

  
    cout << "starting ECU feature activationn\n";

    if(dfs(0))
        cout << " all features enabed successfully\n";
    else
        cout << "\n activation failed due to cycle\n";

    return 0;
}
