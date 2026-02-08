#include<iostream>
#include<functional>
using namespace std;

//correct way to use function to lambdas
/*std::function<int(int,int)>add=[](int a,int b)//generic lambda and function compiles it to char
                           {
                             return a+b;

                           };*/
//not good to use function
/*std::function<char(float,int)>add=[](auto  a,auto b)//generic lambda and function compiles it to char
                           {
                             return a+b;

                           };*/
//gereric lambda better to capture with auto
auto add=[](auto  a,auto b)->float
                           {
                             return a+b;

                           };
int main()
{

float a=10.5;
float b=30.7;
float f=add(a,b);
cout<<f<<endl;
}

