#include<iostream>
using namespace std;
int c;
int main()
{
int a;
static int b;
register int d;
int *p=new int;//
cout<<"auto "<<&a<<endl;
cout<<"static "<<&b<<endl;
cout<<"regiser "<<&d<<endl;
cout<<"exatern "<<&c<<endl;
cout<<"pointer "<<&p<<endl;
cout<<"content in pointer "<<p<<endl;


}
