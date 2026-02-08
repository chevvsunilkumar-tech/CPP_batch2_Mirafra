#include<iostream>
using namespace std;

void fun(auto lam)
{
lam();

}

int main()
{
int a=10;
auto add =[&a]()
          {
         cout<<"hi hello\n";
a=20;
          cout<<a<<endl;
           };

fun(add);
cout<<a<<endl;


}
