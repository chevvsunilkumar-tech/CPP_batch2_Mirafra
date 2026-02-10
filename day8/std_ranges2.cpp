#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main()
{
    std::vector<int> v = {5, 2, 8, 1, 4, 8};

    //  std::ranges::sort
    std::ranges::sort(v);

    std::cout << "After sort: ";
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";


    //  std::ranges::find
    auto it = std::ranges::find(v, 4);

    if (it != v.end())
        std::cout << "Found 4 at index :"  << std::distance(v.begin(), it) << "\n";


    //  std::ranges::copy
    std::vector<int> destination(v.size());

    std::ranges::copy(v, destination.begin());

    std::cout << "After copy: ";
    for (int x : destination)
        std::cout << x << " ";
    std::cout << "\n";


    //  std::ranges::for_each
    std::cout << "Multiply each element by 2: ";
    std::ranges::for_each((v), [](int &x) 
    {
        x *= 2;
        std::cout << x << " ";
    });
    std::cout << "\n";


    //  std::ranges::count
    int count_of_16 = std::ranges::count(v, 16);
    std::cout << "Count of 16: " << count_of_16 << "\n";


    //  std::ranges::all_of
    bool all_positive = std::ranges::all_of(v, [](int x) {
        return x > 0;
    }); 
    /*std::ranges::all_of
     Checks if all elements satisfy a condition. */

    std::cout << "All elements positive? " <<
           std::boolalpha   << all_positive << "\n";

    return 0;
}
