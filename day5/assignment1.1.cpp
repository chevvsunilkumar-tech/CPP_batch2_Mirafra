#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

class temp {
    int* temp_data;

public:
    temp() : temp_data(new int(rand() % 100)) {
        cout << "Constructor executed, value = " << *temp_data << endl;
    }

    ~temp() {
        cout << "Destructor executed\n";
        delete temp_data;
    }

    int getValue() const {
        return *temp_data;
    }
//friend int avgvaluesoftemp(shared_ptr<temp[]> arr, int size); 
friend int avgvaluesoftemp(weak_ptr<temp[]>p, int size); 
};

int avgvaluesoftemp(weak_ptr<temp[]>p, int size) {
    int sum = 0;
auto arr=p.lock();
    for (int i = 0; i < size; i++) {
        sum += *(arr[i].temp_data);
    }

    return sum / size;
}

struct Deletor {
    void operator()(temp* ptr) const {
        cout << "Custom deleter executed (delete[])\n";
        delete[] ptr;
    }
};


int main() {
    const int size = 5;

    shared_ptr<temp[]> room1(new temp[size],Deletor{});
//shared_ptr<temp[]> room1=make_shared<temp[]>(size);  supports only c++20

    cout << "\nAverage temperature: "
         << avgvaluesoftemp(room1, size) << endl;

    return 0;
}

