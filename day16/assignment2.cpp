#include <iostream>
using namespace std;

#define MAX 5


const char* featureNames[MAX] = {
    "engine control",
    "fuel system",
    "ignition",
    "snsor module",
    "logging system"
};


int graph[MAX][MAX] = {0};


int visited[MAX];


void dfs(int node)
{
    
    if(visited[node] == 1)
        return;

    visited[node] = 1;

   
    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i] == 1)
        {
            dfs(i);
        }
    }

    
    cout << "activating the feature: "
         << featureNames[node] << endl;
}

int main()
{
  
    graph[0][1] = 1; // engine → fuel
    graph[0][2] = 1; // engine → ignition
    graph[1][3] = 1; // fuel → sensor
    graph[2][3] = 1; // ignition → Sensor
    graph[3][4] = 1; // sensor → logging

   
    for(int i = 0; i < MAX; i++)
        visited[i] = 0;

    cout << "Starting  Activation...\n";

    dfs(0);

    cout << "all activated successfully completed \n";

    return 0;
}
