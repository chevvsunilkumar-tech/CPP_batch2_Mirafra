#include <algorithm>
#include <iostream>
#include <list>
 
int main()
{
    // Create a list containing integers
    std::list<int> l = {7, 5, 16, 8},l2={11,22};
     
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
    int a=10;
   l.push_back(a);
   l.emplace_back(33);


    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
/*    if (it != l.end())
        l.insert(it, 42);
 */
   l.splice(it,l2);
   l.insert(it,111);

  l2.insert(l2.begin(),l.begin(),l.end());
    // Print out the list
    std::cout << "l = { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";
std::cout<<"\n elemnts of l2\n";
    std::cout << "l = { ";
    for (int n : l2)
        std::cout << n << ", ";
    std::cout << "};\n";
}
