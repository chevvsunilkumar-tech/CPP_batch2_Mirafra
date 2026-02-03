#include <iostream>
#include <cstring>

using namespace std;

class uart {
    char* uart_data;
    int uart_num;
    int uart_speed;

public:
    // Constructor
    uart(int num = 0, int speed = 1000, const char* data = nullptr);

    // Destructor
    ~uart();

    // Copy constructor
    uart(const uart& other);

    // Copy assignment
    uart& operator=(const uart& other);

    // Move constructor
    uart(uart&& other) noexcept;

    // Move assignment
    uart& operator=(uart&& other) noexcept;

    // Set data
    void set_data(const char* p);

    // Get data
    char* get_data();

    // Change specifications
    void change_specs(int speed, int num);

    // Print for testing
    void print_info();
};

uart::uart(int num, int speed, const char* data)
    : uart_num(num), uart_speed(speed) {
    if(data) {
        uart_data = new char[strlen(data) + 1];
        strcpy(uart_data, data);
    } else {
        uart_data = nullptr;
    }
    cout << "Constructor called\n";
}

uart::~uart() {
    cout << "Destructor called\n";
    delete[] uart_data;
}

uart::uart(const uart& other) {
    cout << "Copy constructor called\n";
    uart_num = other.uart_num;
    uart_speed = other.uart_speed;
    if(other.uart_data) {
        uart_data = new char[strlen(other.uart_data) + 1];
        strcpy(uart_data, other.uart_data);
    } else {
        uart_data = nullptr;
    }
}

uart& uart::operator=(const uart& other) {
    cout << "Copy assignment called\n";
    if(this != &other) {
        uart_num = other.uart_num;
        uart_speed = other.uart_speed;

        delete[] uart_data;

        if(other.uart_data) {
            uart_data = new char[strlen(other.uart_data) + 1];
            strcpy(uart_data, other.uart_data);
        } else {
            uart_data = nullptr;
        }
    }
    return *this;
}

uart::uart(uart&& other) noexcept {
    cout << "Move constructor called\n";
    uart_num = other.uart_num;
    uart_speed = other.uart_speed;
    uart_data = other.uart_data;

    other.uart_num = -1;
    other.uart_speed = 0;
    other.uart_data = nullptr;
}

uart& uart::operator=(uart&& other) noexcept {
    cout << "Move assignment called\n";
    if(this != &other) {
        delete[] uart_data;

        uart_num = other.uart_num;
        uart_speed = other.uart_speed;
        uart_data = other.uart_data;

        other.uart_num = -1;
        other.uart_speed = 0;
        other.uart_data = nullptr;
    }
    return *this;
}

void uart::set_data(const char* p) {
    delete[] uart_data;
    if(p) {
        uart_data = new char[strlen(p) + 1];
        strcpy(uart_data, p);
    } else {
        uart_data = nullptr;
    }
}

char* uart::get_data() {
    return uart_data;
}

void uart::change_specs(int speed, int num) {
    uart_speed = speed;
    uart_num = num;
}

void uart::print_info() {
    cout<<"uart_num :"<<uart_num<<endl;
    cout<<"uart_speed :"<<uart_speed<<endl;
    if(uart_data==nullptr)
    cout<<"uart_data  : data is nill\n";
    else
    cout<<"uart_data :"<<uart_data<<endl;
}

int main() {
    uart u1(1, 9600, "Hello");
    u1.print_info();

    // Copy constructor
    uart u2 = u1;
    u2.print_info();

    // Move constructor
    uart u3 = std::move(u1);
    cout<<"u1 after move\n";
     u1.print_info();
    cout<<"u3 after stealing resource from u1 by move constructor\n";
    u3.print_info();

    // Copy assignment
    uart u4;
    u4 = u2;
    u4.print_info();

    // Move assignment
    uart u5;
    u5 = std::move(u2);
    cout<<"u2 after applied move assigmnent\n";
     u2.print_info();
    cout<<"u5 after getting resouce drom u2 by move assignment\n";
    u5.print_info();

    // Change specs and data
    u5.change_specs(115200, 5);
    u5.set_data("New Data");
    u5.print_info();

    return 0;
}

