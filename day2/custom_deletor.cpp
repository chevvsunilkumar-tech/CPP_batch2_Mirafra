#include<iostream>
#include<memory>
#include<cstdlib>
using namespace std;
class custom_del
{
int a;
public:
custom_del(int b):a(b)
{

}

template<typename T>
void operator() (T*p)const
{

free(p);
cout<<a<<endl;
cout<<"memory get freed\n";
}

};



int main()
{
unique_ptr<int,custom_del>p((int *)malloc(4),custom_del);

*p=20;
cout<<*p<<endl;

}
