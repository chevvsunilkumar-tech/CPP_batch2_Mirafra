#include<iostream>
using namespace std;
typedef void(*fptr)(int);

void motor_on(int n)
{
cout<<"motor on and temp is  :"<<n<<endl;
}
void motor_off(int n)
{
cout<<"motor is turn off and temp is :"<<n<<endl;
}



int main()
{

int temp;
fptr fp;
while(1)
{
cout<<"enter the tenparture\n";
cin>>temp;
if(temp>30)
{
fp=motor_on;
fp(temp);

}
else
{
fp=motor_off;
fp(temp);

}

}


}

