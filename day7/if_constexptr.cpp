#include<iostream>
using namespace std;


template<typename T>

void process(T val)
{

if constexpr(sizeof(T)==4)
cout<<"type is 4 bytes\n";
else
cout<<"type is non 4byte\n";

}



int main()
{
int a=50;
process(a);
process('c');
process(10.23);

}
