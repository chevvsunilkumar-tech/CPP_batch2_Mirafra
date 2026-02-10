//error

#include <iostream>
#include<functional>
using namespace std;
function<int()>f;

void fun()
{
    
 int x=10;
f=[&x]()
{
    
    return x;
};
    
}
    


int main()
{
    std::cout<<"Hello World";
    f();

    return 0;
}
