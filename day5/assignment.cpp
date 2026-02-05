#include <iostream>
#include <memory>
#include <cstdlib> 
using namespace std;

class temp {
    int* temp_data;
    int size;
public:
    temp(int n = 5) : size(n), temp_data(new int[n]) {
        cout << "Constructor is executed\n";
        for (int i = 0; i < size; i++) {
            temp_data[i] = rand() % 100;  
        }
    }

    ~temp() {
        cout << "Destructor is executed\n";
        delete [] temp_data;
    }

    int get(int i) const { return temp_data[i]; }

    int getSize() const { return size; }
};

class deletor {
public:
    void operator()(temp* obj) {
        cout << "Custom deleter is executed\n";
        delete obj;  
    }
};

int avgvaluesoftemp(weak_ptr<temp> wp) {
    auto ptr = wp.lock();
    if (!ptr) return 0;    

    int sum = 0;
    for (int i = 0; i < ptr->getSize(); i++) {
        sum += ptr->get(i);
    }

    return sum / ptr->getSize();
}

int main() {
    shared_ptr<temp> room1(new temp, deletor{});  

    cout << "Average of temperatures of room1: "
         << avgvaluesoftemp(weak_ptr<temp>(room1)) << endl;

    return 0;
}

