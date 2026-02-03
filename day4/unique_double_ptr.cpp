#include<iostream>
#include<memory>

using namespace std;
void help(unique_ptr<int>*p)
{
cout<<"help"<<**p<<endl;
*p=make_unique<int>(100);// move assignment called so delete previous memory and allocate new ememory so no memory leak
//**p=100;

}

int main()
{
unique_ptr<int> p=make_unique<int>(10);
//help(move(p));
//help(p);
//help(move(p));
help(&p);
cout<<"main "<<*p<<endl;





}
