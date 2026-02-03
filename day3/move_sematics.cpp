#include<iostream>

using namespace std;

class emp
{
    int id;
    int rank;
public:
    // Parameterized Constructor
    emp(int i=0, int r=0 ):id(i), rank(r) {}

    // Destructor (must delete allocated memory)
    ~emp()
    {
       
    }

    // Copy Constructor (Deep Copy)
   /* emp(const emp &other) : id(other.id), rank(other.rank)
    {
        cout<<"copy constructor\n";
    }

    // Copy Assignment Operator (Deep Copy)
    emp& operator =(const emp &other)
    {
        if(this != &other)
        {
            
            id = other.id;
            rank = other.rank; // Allocate and copy
        }
        cout<<"copy assignment\n";
        return *this;
    }*/
     emp(emp &&e)
     {
cout<<"move constrcutor\n";
    id=e.id;
rank=e.rank;

     }
emp emp(emp&&other)
{
cout
if(&other!=this)

}

};

emp func(int id,int p)
{
emp obj(id,p);
return obj;

}

int main()
{
    emp obj1(10,1);
//    emp obj2 = obj1; // Calls copy constructor
     emp obj3=obj1;
}

