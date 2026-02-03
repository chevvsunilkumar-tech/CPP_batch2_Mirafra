#include<iostream>
#include<memory>

using namespace std;


int data()
{

return 22;
}

void display(shared_ptr<int>p)
{
cout<<"display :"<<*p<<endl;
}

void control(shared_ptr<int>p)
{
*p=12;
cout<<"control :"<<*p<<endl;

}

void log(shared_ptr<int>p)
{
cout<<"log"<<endl;

}


int main()
{
shared_ptr<int> p=make_shared<int>(data());

display(p);
log(p);
control(p);


}
