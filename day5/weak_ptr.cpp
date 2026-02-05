#include <iostream>
#include <memory>
using namespace std;

class B; 

class A {
public:
    weak_ptr<B> p; 

    A() {
        cout << "Constructor of A\n";
    }

    ~A() {
        cout << "Destructor of A\n";
    }
};

class B {
public:
    shared_ptr<A> p; 

    B() {
        cout << "Constructor of B\n";
    }

    ~B() {
        cout << "Destructor of B\n";
    }
};

int main() {
    {
        shared_ptr<A> obj1 = make_shared<A>();
        shared_ptr<B> obj2 = make_shared<B>();

        cout << "Initial ref counts:\n";
        cout << "obj1 use_count: " << obj1.use_count() << endl; // 1
        cout << "obj2 use_count: " << obj2.use_count() << endl; // 1

       
        obj1->p = obj2;
        obj2->p = obj1;

        cout << "\nAfter circular reference:\n";
        cout << "obj1 use_count: " << obj1.use_count() << endl;
        cout << "obj2 use_count: " << obj2.use_count() << endl;
    }

    cout << "\nAfter scope ends, destructors called automatically\n";

    return 0;
}

