#include<iostream>

#include<memory>
using namespace std;
class B;
class A
{
public:
static int c1;
shared_ptr<B>p;

public:
A()
{
c1++;
cout<<"constructor of A\n";
}

~A()
{
c1--;
cout<<"destrcutor od A\n";
}

};

class B
{
public:
static int c2;
 shared_ptr<A>p;

public:
B()
{
c2++;
cout<<"constrcuto of B\n";
}

~B()
{
c2--;
cout<<"dstrctir of B\n";

}

};

int A::c1=0;
int B::c2=0;

//static shared<A> B::p;
//static shared_ptr<A>B::
int main()
{
{

shared_ptr<A>obj1=make_shared<A>();
shared_ptr<B>obj2=make_shared<B>();
cout<<"A ref count "<<A::c1<<endl;
cout<<"B ref count "<<B::c2<<endl; 

obj1->p=obj2;
obj2->p=obj1;
cout<<"A ref count after circular ref "<<A::c1<<endl;//we are using static int c1 which invoke only when constrctor called
cout<<"B ref count after circular ref  "<<B::c2<<endl; 
}
cout<<"A ref count after out of scope "<<A::c1<<endl;
cout<<"B ref count after out of scope "<<B::c2<<endl; 
}



