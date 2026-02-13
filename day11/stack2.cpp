#include <iostream>
#include <stack>
#include <vector>

//std::stack<int, std::vector<int>> s;
template<typename T>
class MyStack : public std::stack<T, std::vector<T>>
{
public:
    using std::stack<T, std::vector<T>>::c;  // expose container
};

int main()
{
    MyStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // Random access via underlying container
   std::cout << "Element at index 1: " << s.c[1] << std::endl;

    return 0;
}

