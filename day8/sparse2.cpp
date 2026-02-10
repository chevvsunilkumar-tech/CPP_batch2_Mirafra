//one of the solution for sparse data //
#include <iostream>
#include <vector>
#include<unordered_map>

int main()
{
    std::vector<std::pair<int,int>> sparse;
unordered_map<int,pair<int,int>>m;
m[0]={3,5};
m[1]={6,3};
    // Insert non-zero elements
    sparse.push_back({3, 5});
    sparse.push_back({6, 3});

    // Print sparse data
    for (const auto& [index, value] : sparse)
    {
        std::cout << "Index: "
                  << index
                  << " Value: "
                  << value << "\n";
    }

    return 0;
}

