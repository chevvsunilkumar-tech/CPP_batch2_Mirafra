#include<iostream>
#include<memory>

using namespace std;


class sharedptr
{

int *data;
int *count;

public:

sharedptr(int d):data(new int(d))
{
count =new int(1);
cout<<"constructor called"<<"data "<<*data<<endl;

}
//destructor
~sharedptr(){
//cout<<"destructor called "<<endl; 
if(count ==0)
{

}
else
{
if(*count==1)
{
 (*count)--;
   delete data;
delete count;
cout<<"destructor called "<<endl; 
}
else
{
(*count)--;
cout<<"after destructor ref count "<<(*count)<<endl;

}
}
}

//copy constructror

sharedptr(const sharedptr &obj)
{

data=obj.data;
count=obj.count;
(*count)++;

cout<<"after copy constrcutor ref count"<<*count<<endl;

}
//copy assigment

sharedptr operator =(const sharedptr &obj)
{
if((this)==&obj)
return *this;

data=obj.data;
count=obj.count;
//*(count)++;
cout<<"aftercopy assigmnet  ref count "<<*count<<endl;
return *this;
}

//move constrcutor
sharedptr(sharedptr &&obj)
{
data=obj.data;
count=obj.count;
obj.data=nullptr;
obj.count=nullptr;
cout<<"move constrcutor after ref count "<<*count<<endl;
}
//move assighmnet
sharedptr operator =(sharedptr && obj)
{
if(this==&obj)
return *this;
data=obj.data;
count=obj.count;
*(count)--;
obj.data=nullptr;
obj.count=nullptr;
return *this;
cout<<"move assignment\n";

}

};


int main()
{
sharedptr p1(10);

{

sharedptr p2=move(p1);

}

}










