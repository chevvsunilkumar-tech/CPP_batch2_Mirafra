#include<iostream>
#include<deque>
using namespace std;

int main()
{
deque<int>dq(5,10);
for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
dq.assign(3,10);
for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
dq={1,2,3,4};
cout<<"dq elements\n";
for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
deque<int>dq2(dq);
cout<<"deq2 elemts\n";
for(auto x:dq2)
{
cout<<x<<" ";
}
cout<<endl;
cout<<"[] and at of 3 \n";
cout<<dq[2]<<" "<<dq.at(2)<<endl;
cout<<"front and back of dq\n";

cout<<dq.front()<<" "<<dq.back()<<endl;

cout<<"size before resize of dq\n";
cout<<dq.size()<<endl;
cout<<"after resize\n";
dq.resize(3);
cout<<dq.size()<<endl;
dq.clear();
dq.insert(dq.begin(),dq2.begin(),dq2.end());
dq.insert(dq.begin(),{11,22,33});
dq.insert(dq.begin(),2,100);
int a=101;
dq.insert(dq.begin()+2,move(a));
for(auto x:dq)
{
cout<<x<<" ";
}

cout<<endl;
dq.emplace(dq.begin(),300);
dq.emplace_back(300);
dq.emplace_front(3000);


for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
dq.push_back(111);
dq.push_front(222);

for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
dq.erase(dq.begin());
dq.erase(dq.begin(),dq.begin()+1);
cout<<"after dq.erase()\n";
for(auto x:dq)
{
cout<<x<<" ";
}
cout<<endl;
}
