#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
 unordered_map<int,int>m;
m[3]=33;
m[10]=100;
m[2]=22;
for(auto x:m)
cout<<x.first<<" "<<x.second<<endl;
cout<<"________________"<<endl;
for(auto [a,b]:m)
cout<<a<<" "<<b<<endl;
    
    return 0;
}


