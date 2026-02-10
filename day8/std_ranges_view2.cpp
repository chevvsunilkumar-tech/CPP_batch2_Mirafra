#include <iostream>
#include <vector>
#include <map>
#include <ranges>
using namespace std;
int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Original: ";
    for (int x : v) 
    std::cout << x << " ";
    std::cout << "\n\n";

    // 1. filter – keep even numbers
    auto even = v | std::views::filter([](int x)
    {
        return x % 2 == 0;
    });

    std::cout << "Filter (even): ";
    for (int x : even) 
    std::cout << x << " ";
    std::cout << "\n";


    //  transform – multiply by 10
    auto multiplied = v | std::views::transform([](int x){
        return x * 10;
    });

    std::cout << "Transform (*10): ";
    for (int x : multiplied) std::cout << x << " ";
    std::cout << "\n";


    //  take – first 5 elements
    auto firstFive = v | std::views::take(5);

    std::cout << "Take (5): ";
    for (int x : firstFive) std::cout << x << " ";
    std::cout << "\n";


    //  drop – skip first 5 elements
    auto skipFive = v | std::views::drop(5);

    std::cout << "Drop (5): ";
    for (int x : skipFive) std::cout << x << " ";
    std::cout << "\n";


    //  reverse
    auto reversed = v | std::views::reverse;

    std::cout << "Reverse: ";
    for (int x : reversed) std::cout << x << " ";
    std::cout << "\n";


    //  keys & values (for associative containers)
    std::map<int, std::string> m = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };
     cout<<"simple range based loop\n";
for(auto x:m)
{
std::cout<<"key :"<<x.first<<" value :"<<x.second<<endl; //we need to use x.first to get key and x.second to get value
}
std::cout<<std::endl;

    std::cout << "Map Keys: ";
    for (auto k : m | std::views::keys)
        std::cout << k << " ";
    std::cout << "\n";

    std::cout << "Map Values: ";
    for (auto v : m | std::views::values)
        std::cout << v << " ";
    std::cout << "\n";

    return 0;
}

