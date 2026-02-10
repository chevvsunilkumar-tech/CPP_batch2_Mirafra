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
x=x*2;
}
cout<<endl;

}

int main()
{
/*vector<int>v={1,2,3,4,5};
print(v);
*/
int *arr=new int[2]{1,2};

span<int>s(arr,2);
cout<<sizeof(s)<<endl;
print<int>(s);
print<int>(s);
//array<int,3>static_arr={1,4,5};
//print(static_arr);
/*int a[]={1,4,5,7};
print(a);
*/


}
