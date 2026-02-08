#include<iostream>
#include<memory>

using namespace std;

int main()
{

shared_ptr <int>p=make_shared<int>(10);
cout<<&p<<endl;
weak_ptr<int>w=p;
cout<<&w<<endl;
cout<<w.lock()<<endl;


}
