#include <memory>
#include <iostream>

class MyObject {
public:
    void greet() {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    std::unique_ptr<MyObject> ptr; // Declared and default-initialized to nullptr

    // Later, assign a new object using std::make_unique
    ptr = new MyObject();

    if (ptr) {
        ptr->greet();
    }

    return 0;
}

