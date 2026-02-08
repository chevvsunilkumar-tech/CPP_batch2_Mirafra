#include<iostream>
using namespace std;


constexpr int mul(int n)
{
constexpr int s=10;
int b=90;
//int s;//error constexpr  should not conti any inilizitilzed avr
//cin>>s;//error

return n*10;

}


int main()
{
//const int n=6; works
//int n=10   wont work
 constexpr int n=10;
constexpr int res=mul(n);
cout<<res<<endl;






}
