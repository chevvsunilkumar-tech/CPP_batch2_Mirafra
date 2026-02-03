
//custom deletor for files

#include<iostream>
#include<memory>
#include<cstdlib>
#include<cstdio>

using namespace std;
class custom_del
{
public:
template<typename T>
void operator() (T*p)const
{

//fclose(p);
//cout<<"file is closed\n";
cout<<"array gets cleaned\n";
delete []p;
}

};



int main()
{
//unique_ptr<FILE,custom_del>p(fopen("sunil.txt","w"),custom_del());

unique_ptr<int [],custom_del>p(new int [10],custom_del());

//*p=20;
//cout<<*p<<endl;

}
