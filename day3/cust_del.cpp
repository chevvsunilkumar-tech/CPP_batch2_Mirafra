#include<iostream>
#include<memory>
using namespace std;
class gpio
{
public:
bool state;


gpio(bool s)
{
state=s;

}
~gpio()
{
cout<<"destructor is called\n";
}

void ipdir()
{
state=false;
cout<<"gpio pin is in ipdir\n";
}
void opdir()
{
state=true;
cout<<"state is in opdir\n";
}


};

class cust_del
{

public:
bool clock;
/*cust_del(bool c):clock(c)
{


}*/

template<typename T>
void operator ()(T obj)
{

if(obj->state)
{
obj->state=false;
cout<<"gpio pin get released\n";
}

else
{

cout<<"gpio pin already in ip dir\n";
}

cout<<"custom deletor called\n";
delete obj;}

};

int main()
{

//unique_ptr<gpio,cust_del>ptr(new gpio(false),cust_del(true));

//unique_ptr<gpio,cust_del>ptr(new gpio(false),cust_del{false});
cust_del obj{};
unique_ptr<gpio,cust_del>ptr(new gpio(false),obj);

ptr->opdir();


}
