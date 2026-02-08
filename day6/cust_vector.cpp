#include<iostream>
using namespace std;

class IntVector
{
int cap;
int size;
int *data;
public:

IntVector():data(nullptr),size(0),cap(0)
{

}
void pop_back()
{

size--;
data[size]=0;
}
void push_back(int d)
{
if(size==cap)
realloc();

data[size++]=d;

}

int cpacity()
{
return cap;
}

int vsize()
{
return size;
}

int & operator [](int idx)
{
return data[idx];
}


private:

void realloc()
{
int rsize;
size==0?rsize=1:rsize=2*size;
if(rsize==1)
data=new int;
else
{
int *temp=new int[rsize];

for(int i=0;i<size;i++)
temp[i]=data[i];
delete []data;
data=temp;

}
cap=rsize;
}

};

int main()
{
IntVector obj;

for(int i=0;i<5;i++)
{
cout<<"size "<<obj.vsize()<<" capacity "<<obj.cpacity()<<endl;
obj.push_back(i);
}

cout<<"elemnts inside \n";
obj.pop_back();
for(int i=0;i<5;i++)
cout<<obj[i]<<" ";

}


