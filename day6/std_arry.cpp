#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void mul_by_10(array<int,5>&arr)
{
int i=0;
for(int &x:arr)
{
//x=x*10;
//arr[i]*=10;

}

}
int main()
{
array<int,5>arr;
cout<<"all eements in array\n";
fill(arr.begin(),arr.end(),10);
for(auto &x:arr)
{
cout<<x<<endl;
}
cout<<"_______________"<<endl;
//cout<<"3 ind elemnt "<<arr.at(10)<<endl;
cout<<"current size "<<arr.size()<<endl;
cout<<"max size "<<arr.max_size()<<endl;

cout<<"front elemnt "<<arr.front()<<endl;
cout<<"back elemt "<<arr.back()<<endl;
cout<<"array aftre sorting\n";
mul_by_10(arr);
sort(arr.begin(),arr.end());

for(auto &x:arr)
{
cout<<x<<endl;
}

}
