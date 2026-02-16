#include<list>
#include<iostream>
#include<iterator>
using namespace std;
int main()
{
    std::list<int> l1 = {1,2,3};
    std::list<int> l2 = {10,20};
    auto it = l2.begin();// points to 10

    l1.splice(l1.begin(), l2, it);
    for (int x : l1)
        std::cout << x <<" ";
  cout<<endl;
cout<<"elemts of list2 after splice of first elemt\n";
for(int x:l2)
cout<<x<<" ";
cout<<endl;
auto it1=l1.begin();
advance(it1,3);
l1.splice(l1.begin(),l1,it1);

cout<<"moving into l1 1 elemts to last elemts\n";
for(int x:l1)
cout<<x<<" ";
cout<<endl;

}
