#include<iostream>
#include<optional>
//#include<list>

using namespace std;
template<typename T>
class queue {
    list<T> l;

public:

  queue()
{

}
    // copy from list
    queue(const std::list<T>& other) {
        l = other;
    }

    // move from list
    queue(std::list<T>&& other) {
        l = std::move(other);
    }

    // copy assignment
    queue& operator=(const queue& other) {
        l = other.l;
        return *this;
    }

    // move assignment
    queue& operator=(queue&& other) {
        l = std::move(other.l);
        return *this;
    }


    void push(T val) {
        l.push_back(val);
    }

    void pop() {
        if (!l.empty())
            l.pop_front();
        else
            cout << "underflow queue\n";
    }

    optional<T> front() const {
        if (!l.empty())
            return l.front();
        return nullopt;
    }

    optional<T> back() const {
        if (!l.empty())
            return l.back();
        return nullopt;
    }

    bool empty() const {
        return l.empty();
    }

    int size() const {
        return l.size();
    }
    void clear()
{
l.clear();
}
};

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
list<int>l={11,22,33};
queue<int>q2=l;
cout<<"q2 elements\n";
    while (!q2.empty()) {
        cout << "Popping: " << *q2.front() << "\n";
        q2.pop();
    }
    if (auto a = q.front())
        cout << "Front: " << *a << "\n";

    auto a =q.back();
         if(a.has_value())
        cout << "Back: " << *a << "\n";
         else
         cout<<"underflow queu\n";

    // Pop all elements safely
    while (!q.empty()) {
        cout << "Popping: " << *q.front() << "\n";
        q.pop();
    }
     //for underflow
     q.pop();
    return 0;
}

