#include<vector>
#include<iostream>

using namespace std;


int main()
{
//vector<int>v{{1,2,3,4}};
//vector<int>v{1,2,3,4};
vector<int>v={1,2,3,4};

cout<<"vector elemts\n";
for(auto &x:v)
{
cout<<x<<" ";
}
cout<<endl;
v.push_back(10);
v.push_back(100);

cout<<"vector elemts\n";
for(auto &x:v)
{
cout<<x<<" ";
}
cout<<endl;
cout<<"front and back "<<v.front()<<" "<<v.back()<<endl;
v.pop_back();
cout<<"pop back after "<<endl;

for(auto &x:v)
{
cout<<x<<" ";
}
cout<<endl;


}
