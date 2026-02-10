#include<iostream>
#include<vector>
#include<ranges>
#include<algorithm>

using namespace std;



int main()
{
vector<int>v={1,2,4,3,4,7,5};
cout<<"before sort\n";
for(auto &x:v)
{
cout<<x<<" ";
}
cout<<endl;
ranges::sort(v);
cout<<"after the sort\n";
for(auto &x:v)
cout<<x<<" ";
cout<<endl;
v.push_back(2);
v.push_back(100);
v.push_back(22);
cout<<"after push_back()\n";
for(auto &x:v)
{
cout<<x<<" ";
}
cout<<endl;
auto it=ranges::find(v,100);
cout<<"100 in v at inde x "<<distance(v.begin(),it)<<endl;



}





