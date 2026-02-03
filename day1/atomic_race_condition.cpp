#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

atomic<int> s{0};

 void inc()
{

for(int i=0;i<1000;i++)
{
s++;
}

}


int main()
{
thread t1(inc);
thread t2(inc);


t1.join();
t2.join();

cout<<s<<endl;



}
