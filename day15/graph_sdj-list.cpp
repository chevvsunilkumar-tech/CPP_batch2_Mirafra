#include <iostream>
#include<unordered_map>
#include<list>

using namespace std;

class adj_list_graph
{
   unordered_map<int,list<int>>adj_l;
public:

   

    void add_edge(int s, int d, bool directed=false)
    {
        // undirected graph
            adj_l[s].push_back(d);
//direceted
        if(!directed)
       adj_l[d].push_back(s);
    }

    void print_graph()
    {
        for (auto &row : adj_l)
        {
               cout<<row.first<<"->";
            for (auto &val : row.second)
                cout<<val<<" ";
            cout << endl;
        }
    }
};

int main()
{
    adj_list_graph obj;

    cout << "Empty graph\n";
    obj.print_graph();

    cout << endl;

    obj.add_edge(1, 2);
    obj.add_edge(2, 4,true);
    obj.add_edge(2, 3);
    obj.add_edge(3, 4);

    cout << "After adding edges\n";
    obj.print_graph();

    return 0;
}

