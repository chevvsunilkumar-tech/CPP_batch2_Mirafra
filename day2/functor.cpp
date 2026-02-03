#include<iostream>

using namespace std;


class led
{
bool ld;
bool sw;

public:

led(bool b=false,bool s=false):ld(b),sw(s)
{
}

void switchstate(bool swit)
{
if(swit==sw)
{
cout<<"switch is already in given state\n";
return;
}
if(sw!=swit)
{
if(sw)
{
sw=swit;
cout<<"now switch is off\n";

}
else
{
sw=swit;
cout<<"now switch is on\n";
}
}
}


void ledstate(bool ledd)
{
if(ld==ledd)
{
cout<<"led  is already in given state\n";
return;
}
if(ld!=ledd)
{
if(ld)
{
ld=ledd;
cout<<"now led is off\n";

}
else
{
ld=ledd;
cout<<"now led is on\n";
}
}
}



void operator()(bool lstate)
{
 ledstate(lstate);

}

void operator()(bool lstate,bool sstate)
{
switchstate(sstate);
ledstate(lstate);

}



};

int main()
{
led obj;

obj(true,false);
obj(true);

}












