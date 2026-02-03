#include<iostream>

using namespace std;

class A
{
int a;
public:
A(int b):a(b)
{
cout<<"conatrcutor\n";
}
~A()
{
cout<<"destructor\n";
}
A(const A&)
{
cout<<"copy constrcutor\n";

}
A(A&&)
{
cout<<"move constrcutor\n";
}



};
A create()
{
//return A(1);
A obj1(2);
return obj1;
}


int main()
{

A obj =create();

}
