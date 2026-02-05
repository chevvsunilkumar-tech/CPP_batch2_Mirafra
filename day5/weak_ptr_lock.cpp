#include<iostream>
#include<memory>


using namespace std;

class A
{

public:

A()
{
cout<<"constrctor\n";
}
~A()
{
cout<<"destrcucot\n";
}

};

int main()
{

weak_ptr<A>w;
{
shared_ptr<A>p=make_shared<A>();
shared_ptr<A>p2=p;
cout<<"ref count p "<<p.use_count()<<endl;
w=p;
//w.expired();
cout<<"after weak ptr ref count "<<p.use_count()<<endl;//weak ptr use coun will be either 0(only if weak ptr dont point to any shared ptr) or 1(only if resouce is valid )

//auto wp=w.lock();
//cout<<"after weak ptr uses lock to convert shared ptr ref count "<<p.use_count()<<endl;
*(w.lock());
}
cout<<"weak count "<<w.use_count()<<endl;
/*
if(w.lock())
{
cout<<"shared ptr is alive\n ";
}
else
cout<<"shared ptr is not ae\n";
*/

if(w.expired())
{
cout<<"not alive\n";
}
else
cout<<"alive\n";


}
