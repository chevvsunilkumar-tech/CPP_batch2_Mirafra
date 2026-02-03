#include<iostream>
using namespace std;

class A
{
public:
int a;
 int operator +(A &obj)
{
return obj.a+a;
}

friend int operator +(A &obj1,A &obj2);
};

/*int operator +(A &obj1,A &obj2)
{
return obj1.a+obj2.a;

}*/


int main()
{
A obj1,obj2;

obj1.a=10;
obj2.a=20;
cout<<obj1+obj2<<endl;


}
