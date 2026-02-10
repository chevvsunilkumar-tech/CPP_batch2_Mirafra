#include <iostream>
#include <list>
using namespace std;

int main() {

    // operator=
    list<int> l1 = {1, 2, 3};
    list<int> l2;
    l2 = l1;

    // assign
    l2.assign(3, 10);
    l2.assign({5, 6, 7});

    // front / back
    cout << "Front: " << l2.front() << endl;
    cout << "Back : " << l2.back()  << endl;

    // empty / size / max_size
    cout << "Empty: " << l2.empty() << endl;
    cout << "Size : " << l2.size()  << endl;
    cout << "Max  : " << l2.max_size() << endl;

    // clear
    l2.clear();
    cout << "After clear, size: " << l2.size() << endl;

    // insert
    list<int> l3 = {1, 4};
    auto it = l3.begin();
    ++it;
    l3.insert(it, 2);
    l3.insert(it, 2, 3);
    l3.insert(it, {5, 6});

    // emplace
    l3.emplace(l3.begin(), 0);

    // erase
    it = l3.begin();
    l3.erase(it);
    l3.erase(l3.begin(), l3.end());

    // push_back / emplace_back / pop_back
    l3.push_back(10);
    l3.emplace_back(20);
    l3.pop_back();

    // push_front / emplace_front / pop_front
    l3.push_front(1);
    l3.emplace_front(0);
    l3.pop_front();

    // resize
    l3.resize(5);
    l3.resize(7, 100);

    // swap
    list<int> l4 = {7, 8, 9};
    l3.swap(l4);

    // merge (lists must be sorted)
    list<int> m1 = {1, 3, 5};
    list<int> m2 = {2, 4, 6};
    m1.merge(m2);

    // splice
    list<int> s1 = {1, 2, 3};
    list<int> s2 = {4, 5};
    s1.splice(s1.end(), s2);

    // remove 
    s1.remove(2);
    s1.remove_if([](int x) { return x % 2 == 0; });

    // reverse
    s1.reverse();

    // unique (only consecutive duplicates)
    list<int> u = {1, 1, 2, 2, 3, 3};
    u.unique();

    // sort
    list<int> so = {4, 2, 1, 3};
    so.sort();


    // final print
    cout << "Final list contents: ";
    for (int x : so)
        cout << x << " ";
    cout << endl;

    return 0;
}

