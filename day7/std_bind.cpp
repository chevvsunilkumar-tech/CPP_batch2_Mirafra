#include<iostream>
#include<functional>


using namespace std;


double avg(int a,int b,int c)
{
return (a+b+c)/3;

}


int main()
{

auto bind_avg=bind(avg,10,placeholders::_1,placeholders::_2);


cout<<bind_avg(2000,30,11)<<endl;



}
