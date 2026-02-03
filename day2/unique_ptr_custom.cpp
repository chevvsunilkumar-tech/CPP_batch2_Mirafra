#include<iostream>

using namespace std;


template<typename T>
class unique_p
{
private:
T *ptr;
public:
explicit unique_p(T *p=0):ptr(p)
{
cout<<"unique consrcutor\n";

}

~ unique_p()
{
cout<<"destructtor if unique\n";

delete ptr;

}

T* operator ->() const
{
return ptr;
}

T* operator *()
{
return *ptr;

}

/*T* release()
{

temp=ptr;
delete ptr;
return ptr;

return ptr;

}
*/
void reset(T*pt=nullptr )
{
delete ptr;
ptr=pt;

}

unique_p (T &&other)
{
if(other.ptr!=ptr)
{
ptr=other.ptr;
other.ptr=nullptr;
}

cout<<"move constrcutor caleed";

}

T & operator =(T && obj)
{
if(obj.ptr==ptr)
return *this;
T *temp=obj.ptr;
obj.ptr=nullptr;

return *this;

}

};


class A
{
public:
A()
{
cout<<"vconstrcutor of A\n";
}

~A()
{
cout<<"destrucor of A\n";
}

void print()
{
cout<<"printed \n";
}

};


int main()
{
unique_p<A>p1(new A()),p2;
//p1.reset();
//p2=p1.release()
p2->print();


}
