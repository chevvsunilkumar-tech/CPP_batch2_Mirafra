#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm> 

using namespace std;

class sparse
{
    vector<pair<int, int>> data; 

public:
    void set(int idx, int val)
    {
        data.push_back({idx, val}); 
    }

    int get(int idx)
    {
        for (auto const& [i, v] : data) 
        {
            if (i == idx)
            {
                return v;
            }
        }
        return 0; 
    }

    void print()
    {
        for (auto const& x : data) // Use const reference for efficiency
        {
            cout << "idx :" << x.first << " data: " << x.second << endl;
        }
    }
};

int main()
{
    sparse obj;

    obj.set(0, 10);
    obj.set(1, 12);
    
    cout << "Value at index 0: " << obj.get(0) << endl; 
    cout << "Value at index 5 (default): " << obj.get(5) << endl; 

    obj.print();

    return 0;
}

