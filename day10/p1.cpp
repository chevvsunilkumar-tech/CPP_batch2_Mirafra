#include <iostream>
#include<list>
using namespace std;

int main()
{
list<int>l1={1,2,3};
list<int>l2=l1;

l1.push_back(10);

for(int x:l2)
{
cout<<x<<endl;
}
    
    return 0;
}


