#include<iostream>
using namespace std;


class led
{
public:

void ledblink()
{
cout<<"led b,ink\n";
}

void ledtoggle()
{
cout<<"led toggle\n";
}

void display(const bool&a)
{
if(a)
cout<<"on\n";
else
cout<<" off\n";

}


};

int main()
{
led obj;
bool a=true;

obj.ledblink();

obj.ledtoggle();

obj.display(a);

}
