#include <iostream>
using namespace std;
struct S
{
mutable int data;
double d;

};

S f()
{

return S{10,12.22};
}


int main()
{
const  auto&[a,b]=f(); //if not const we can not becuse it is rvalue

a=20; //a is const but it is mutable too
//b=22.22;//error becuse it is const 
cout<<a<<" "<<b<<endl;    
    return 0;
}


