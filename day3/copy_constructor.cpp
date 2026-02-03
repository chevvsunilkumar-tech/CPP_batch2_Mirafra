#include<iostream>

using namespace std;

class emp
{
    int id;
    int *rank;
public:
    // Parameterized Constructor
    emp(int i=0, int r=0 ):id(i), rank(new int (r)) {}

    // Destructor (must delete allocated memory)
    ~emp()
    {
        delete rank;
    }

    // Copy Constructor (Deep Copy)
    emp(const emp &other) : id(other.id), rank(new int(*other.rank))
    {
        cout<<"copy constructor\n";
    }

    // Copy Assignment Operator (Deep Copy)
    emp& operator =(const emp &other)
    {
        if(this != &other)
        {
            delete rank; // Delete old memory
            id = other.id;
            rank = new int(*other.rank); // Allocate and copy
        }
        cout<<"copy assignment\n";
        return *this;
    }
};

int main()
{
    emp obj1(10,1);
    emp obj2 = obj1; // Calls copy constructor
}

