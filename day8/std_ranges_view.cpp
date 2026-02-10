#include<iostream>
#include<ranges>
#include<vector>

using namespace std;

int main()
{
vector<int>v={1,2,34,56,7,88,55,8,86};
cout<<"elemnts of orginal vector\n";
for(int x:v)
cout<<x<<" ";
cout<<endl;

/*auto above_50=v|std::views::filter([](int x)
{

return x>50;
}|std::views::take(1));*/
/* auto above_50 =
        v
        | std::views::filter([](int x) {
              return x > 50;
          })
        | std::views::take(1);//only takes 1 
*/
auto above_50 =
    v |std::views::drop(4)|std::views::take(2)| std::views::filter([](int x) {
            return x>50;
        });// we are feeding from 4 th index to 5th index 


cout<<"above 50 output\n";
for(int x:above_50)
{

cout<<x<<" ";
}
cout<<endl;
cout<<"after filter original vcetor\n";
for(int x:v)
cout<<x<<" ";
cout<<endl;

auto t=v|std::views::transform([](int &x)
{
//x=x*x;
//return (x= x*x);  // it will modifuy the original vectr\or
return (x*x);
});
cout<<"transform output\n";
for(int x:t)
cout<<x<<" ";
cout<<endl;
cout<<"aftre transform original vector \n";

for(int x:v)
cout<<x<<" ";
cout<<endl;

}
