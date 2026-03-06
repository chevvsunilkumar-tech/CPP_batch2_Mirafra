#include <iostream>
#include<vector>

using namespace std;
class graph
{
int V;
vector<vector<int>>adj_m;
public:

graph(int size):V(size)
{

adj_m.resize(V,vector<int>(V,0));


}
void add_edge(int s,int d)
{
//undirected graph
adj_m[s][d]=1;
adj_m[d][s]=1;


}

void print_graph()
{

for(auto it1:adj_m)
{
for(auto it2:it1)
cout<<it2<<" ";
cout<<endl;

}

}




};

int main()
{
graph obj(5);

obj.print_graph();

cout<<endl;
obj.add_edge(1,2);
obj.add_edge(2,4);
obj.add_edge(2,3);
obj.add_edge(3,4);

obj.print_graph();

    
    return 0;
}


