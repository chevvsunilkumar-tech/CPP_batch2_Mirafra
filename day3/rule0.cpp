//rule of 0


#include<iostream>
#include<vector>
using namespace std;
class car
{
vector<int>car_no;
public:
//constructor
car(int a=0):car_no(a,0)
{
}
//no copy consructor

// no copy asssignment

void set(int ind,int data)
{
car_no[ind]=data;

}

void print()
{

for(auto &x:car_no)
{

cout<<"car no :"<<x<<endl;

}

}


};

int main()
{
cout<<"obj1 with 2 elelments\n";
car obj(2);
obj.set(0,10);
obj.set(1,11);
obj.print();
cout<<"obj2 copied from obj\n";
car obj2=obj;
obj2.print();
cout<<"onj3 creted with 4 elments\n";
car obj3(4);
obj3.set(0,2);
obj3.set(1,3);
obj3.set(2,4);
obj3.set(3,5);
obj3.print();
cout<<"onj3 is creadted by copiying from obj2\n";
obj=obj3;
obj.print();

}


