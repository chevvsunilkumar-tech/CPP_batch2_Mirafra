#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(int a)
{
cout<<a<<" "; 

}

int main()
{

vector<int>v={1,2,3,45,5};
auto lam=[](int a)
           {
      
         cout<<a<<" ";
           };
//for_each(v.begin(),v.end(),lam);
for_each(v.begin(),v.end(),print);
cout<<endl;
}
