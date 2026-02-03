#include<iostream>
using namespace std;


class A 
{
public:
int a;
float b;
public:
/*A(int a,float b)
{
cout<<"constrcutor\n";
}*/

};
int main()
{
//A obj;// a is initilized with garbage
// A obj() it is a function declaration not object crestion
A obj{10,12.22}; //it only initilize the 'a' with a zero if not construcor exist 
cout<<"obj.a "<<obj.a<<endl;
cout<<"obj.b "<<obj.b<<endl;


}
