#include <iostream>
#include<map>

using namespace std;

int main()
{
map<int,string>m={{1,"one"},{2,"two"},{3,"three"}};


for(auto x:m)
cout<<x.first<<" "<<x.second<<endl;
cout<<"with strcutre binding\n";

for(const auto [a,b]:m )
cout<<a<<" "<<b<<endl;




    
    return 0;
}


