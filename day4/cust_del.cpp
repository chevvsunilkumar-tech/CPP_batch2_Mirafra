#include<iostream>
#include<memory>

using namespace std;


class A
{
public:

A()
{
cout<<"A constrcutor\n";
}



};
class cust_del
{
//int a;
public:
void operator ()(A obj)
{

}
~cust_del()
{

}
};
 
int main()
{
//cust_del obj{};
unique_ptr<A,cust_del>(new A,cust_del());

}
