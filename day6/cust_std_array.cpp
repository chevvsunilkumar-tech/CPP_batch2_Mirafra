#include<iostream>
using namespace std;

class IntArray
{
int arr[5];

public:

int size()
{
return 5;

}

int at(int idx)
{
if(idx>=5)
{
throw "out of bound access\n";
}
return arr[idx];

}

int& operator [](int idx)
{

return arr[idx];
}


int front()
{
return arr[0];
}

int back()
{
return arr[5];
}

int * begin()
{
return arr;

}
int * end()
{

return arr+5;
}

/*const int *& begin()
{
return arr;

}
*/

void fill(int *begin,int *end,int val)
{
for(;begin!=end;begin++)
{
*begin=val;
}
}

};

int main()
{
IntArray obj;

cout<<" size :"<<obj.size()<<endl;

/*for(int i=0;i<obj.size();i++)
{
cin>>obj[i];

}*/
fill(obj.begin(),obj.end(),1);

for(int i=0;i<obj.size();i++)
{
cout<<obj[i]<<" ";
}
//cout<<"what is at 2 "<<obj.at(45)<<endl;



}
