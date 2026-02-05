#include<iostream>

#include<memory>
using namespace std;
class A
{
int *p;
public:
A(int a):p(new int(a))
{
cout<<"A constructor\n";

}
void print()
{
cout<<"value: "<<*p<<endl;
}
~A()
{
delete p;
cout<<"A destructor\n";
}

};

class del
{

public:
del()
{

cout<<"deletor constructor\n";
}
~del()
{

cout<<"deletor detrstructor\n";
}

void operator ()(A *obj) 
{
cout<<"custom deleltor \n";
delete obj;
}

};

int main()

{
//shared_ptr<A,del>p(new A(),del{});  error because shared pt template does not take deletor
shared_ptr<A>p(new A(10),del{});  //no error because it takes it as a prametr to store in control bolck
}


