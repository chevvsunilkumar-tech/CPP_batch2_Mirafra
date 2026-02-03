#include<iostream>
#include<vector>
using namespace std;

int main()
{
int a=10;
const int b=10;
int *p=&a;
const int *q=&b;
const int * const s=&b;

//int *&c=q;
const int &t=a;
//const int *&c=p;
const int * const &c1=s;
}
