#include<iostream>
using namespace std;

/*
int func()
{

return 10;

}
*/
int & func(int a)
{
cout<<"int a"<<endl;
return a;
}

void func(int &a)
{
cout<<"int &a";
}

void func(const int &a)
{

cout<<"const int 7a\n";
}

void func(int &&a)
{

}

int main()
{
/*
int x=11;
int & l1=x;
int &l2=func(x);
int &&r1=111;
int &&r2=func();
cout<<&r2;*/

int a=10;
//func();
func(10);
}
