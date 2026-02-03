#include<iostream>
using namespace std;

class B
{
public:
int c;

};

class A 
{
public:
float a;
int b;
B d;
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
A obj; //it only initilize the 'a' with a zero if not construcor exist 
cout<<"obj.a "<<obj.a<<endl;
cout<<"obj.b "<<obj.b<<endl;
cout<<"strcut "<<obj.d.c<<endl;

}
