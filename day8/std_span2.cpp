#include<iostream>
#include<array>
#include<vector>
#include<span>

using namespace std;
template<typename T>
void print(span<T>s)
{
for(int &x:s)
{
cout<<x<<" ";
//x=x*2;
}
cout<<endl;

}

int main()
{
vector<int>v={1,2,3,4,5};
span<int>s(v);

span<int>s_first=s.first(2);
print<int>(s_first);
span<int>s_last=s.last(2);
print<int>(s_last);
span<int>s_sub=s.subspan(2,3);
print<int>(s_sub);

cout<<s_first[0]<<endl;

//cout<<s_first.at(1)<<endl;
}
