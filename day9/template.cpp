#include <iostream>
#include<vector>
#include<list>
#include<array>
using namespace std;


template<typename T>

void print_all(T first,T last)
{
while(first!=last)
{
cout<<*first<<" "<<endl;
first++;
}
cout<<endl;


}



int main()
{
array<int,5>arr={1,2,3,4,5};
vector<int>v={11,22,33,44,55};
list<int>l={12,23,34,45,56};
int a[]={0,1,2,20,20};

cout<<"vector elemnts\n";
print_all(v.begin(),v.end());
print_all(arr.begin(),arr.end());
print_all(l.begin(),l.end());    
    return 0;
}


