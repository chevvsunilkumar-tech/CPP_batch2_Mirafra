#include <iostream>
#include <stack>
using namespace std;

#define MAX 5

// Adjacency matrix (Directed Graph)
int graph[MAX][MAX] = {0};

// Visited array
bool visited[MAX];

// Iterative DFS
void dfs_iterative(int start)
{
    stack<int> st;
    st.push(start);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            visited[node] = true;
            cout << "Activating Feature: " << node << endl;

            // Push neighbors in reverse order
            // So lower index gets processed first
            for(int i = 0; i <MAX; i++)
            {
                if(graph[node][i] == 1 && !visited[i])
                {
                    st.push(i);
                }
            }
        }
    }
}

int main()
{
    // Example Feature Dependencies
    // 0 → 1,2
    // 1 → 3
    // 2 → 3
    // 3 → 4

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    // Initialize visited array
    for(int i = 0; i < MAX; i++)
        visited[i] = false;

    cout << "Starting ECU Feature Activation:\n\n";

    dfs_iterative(0);

    return 0;
}
