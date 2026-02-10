#include <iostream>
#include <forward_list>
using namespace std;

int main() {

    //  Create forward_list
    forward_list<int> fl = {2, 3, 4};

    //  push_front
    fl.push_front(1);   // 1 2 3 4

    cout << "After push_front: ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  front
    cout << "Front element: " << fl.front() << endl;

    //  insert_after
    auto it = fl.before_begin();   // before first element
    fl.insert_after(it, 0);        // 0 1 2 3 4

    cout << "After insert_after: ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  emplace_after
    fl.emplace_after(it, -1);      // -1 0 1 2 3 4

    cout << "After emplace_after: ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  erase_after
    fl.erase_after(it);            // removes -1

    cout << "After erase_after: ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  remove
    fl.remove(3);

    cout << "After remove(3): ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  remove_if
    fl.remove_if([](int x) { return x % 2 == 0; });

    cout << "After remove_if(even): ";
    for (int x : fl) cout << x << " ";
    cout << endl;

    //  unique (removes consecutive duplicates)
    forward_list<int> fl2 = {1, 1, 2, 2, 3, 3};
    fl2.unique();

    cout << "After unique: ";
    for (int x : fl2) cout << x << " ";
    cout << endl;

    //  sort
    forward_list<int> fl3 = {4, 1, 3, 2};
    fl3.sort();

    cout << "After sort: ";
    for (int x : fl3) cout << x << " ";
    cout << endl;

    //  reverse
    fl3.reverse();

    cout << "After reverse: ";
    for (int x : fl3) cout << x << " ";
    cout << endl;

    //  splice_after
    forward_list<int> a = {1, 2};
    forward_list<int> b = {3, 4};

    a.splice_after(a.before_begin(), b);

    cout << "After splice_after: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "b size after splice (empty): ";
    for (int x : b) cout << x << " ";
    cout << endl;

    //  clear
    a.clear();
    cout << "After clear, empty: " << a.empty() << endl;

    return 0;
}

