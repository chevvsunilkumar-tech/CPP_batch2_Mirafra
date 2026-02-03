#include<iostream>
#include<vector>
using namespace std;
const int & display(const int &a)
{

return a;

}

int main()
{
// int *&p=new int;
int a=10;
cout<<display(a);
vector<int>v{1,23,4,5};

for(const auto &x:v)
{
cout<<x<<endl;

}


}
