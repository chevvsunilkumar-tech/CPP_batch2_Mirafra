#include <iostream>

using namespace std;
consteval int add(int a,int b)
{

return a+b;
}


int main()
{
//int x=10;

// int a=add(1,2);   //depend o compiler no error
constexpr int a=add(1,2);
    return 0;
}


