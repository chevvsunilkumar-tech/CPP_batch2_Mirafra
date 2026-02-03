#include<iostream>
#include<memory>
using namespace std;
class A
{
unique_ptr<int>ptr;
public:

A(int a):ptr(make_unique<int>(a))
{

}

void show()
{
cout<<"value :"<<*ptr<<endl;

}

};


int main()
{
{
unique_ptr<A>p = make_unique<A>(20);
p->show();
}
//unique_ptr<A>p2;

}
