#include<iostream>
#include<memory>
using namespace std;

void change(int *p)
{
*p=20;
cout<<endl;
cout<<"addrss :"<<p<<"value :"<<*p<<endl;
//delete p;
}


int main()
{
unique_ptr<int>up=make_unique<int>(10);
cout<<"before passing\n";
cout<<"unique ptr value :"<<*up<<"address of up :"<<&up<<"adress of ptr inside up :"<<up.get()<<"value of ptr inside up :"<<*up.get()<<endl;
change(up.get());
cout<<"after passig\n";
cout<<"value :"<<*up.get()<<endl;
if(up)
{
cout<<"ownershp not transfered\n";
}
else
{
cout<<"ownership get transferd\n";
}
}
