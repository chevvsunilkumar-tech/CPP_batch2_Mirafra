#include<iostream>
using namespace std;
int & func(int &a)
{

return a;

}

int main()
{
/*int a=10;
int &b=a;
const int &p=func(a);
cout<<func(a)<<endl;

cout<<&a<<" "<<&b<<endl;
*/

int a=10;
const int &b=a;
a=10;

}
