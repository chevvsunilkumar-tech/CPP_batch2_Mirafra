#include <iostream>
#include <initializer_list>
using namespace std;

template<typename T>
class list {
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };

    int _size;
    Node* head;
    Node* tail;

public:

    class iterator {
        Node* current;
        friend class list<T>;

    public:
        iterator(Node* ptr = nullptr) : current(ptr) {}

        T& operator*() const {
            return current->data;
                   }
        T* operator->() const { 
               return &(current->data);
                }
        Node* get() {
          return current; 
                }

        iterator& operator++() {
             if (current) current = current->next;
 return *this; 
                         }
        iterator operator++(int) { 
 iterator temp = *this;
 ++(*this);
 return temp;
           }
        iterator& operator--() {
              if (current) current = current->prev; 
return *this;
                          }
        iterator operator--(int) { 
        iterator temp = *this;
                    --(*this);
                     return temp;
                       }

        bool operator==(const iterator& other) const {
           return current == other.current;
                  }
        bool operator!=(const iterator& other) const {
          return current != other.current; 
              }
    };

    iterator begin() {
         return iterator(head); 
          }
    iterator end() { 
 return iterator(nullptr); 
    }

    // Default / parameterized constructor
    list(int s = 0, T d = T()) : head(nullptr), tail(nullptr), _size(0) {
        for (int i = 0; i < s; i++)
              push_back(d);
    }

    // Initializer list constructor
    list(initializer_list<T> l) : head(nullptr), tail(nullptr), _size(0) {
        for (auto it = l.begin();
          it != l.end(); ++it) push_back(*it);
    }

    // Copy constructor
    list(const list &other) : head(nullptr), tail(nullptr), _size(0) {
        Node* current_other = other.head;
        while (current_other) {
            push_back(current_other->data);
            current_other = current_other->next;
        }
    }

    // Move constructor
    list(list &&other) : head(other.head), tail(other.tail), _size(other._size) {
        other.head = other.tail = nullptr;
        other._size = 0;
    }

    // Copy assignment
    list& operator=(const list& other) {
        if (this != &other) {
            clear();
            Node* current_other = other.head;
            while (current_other) {
                push_back(current_other->data);
                current_other = current_other->next;
            }
        }
        return *this;
    }

    // Move assignment
    list& operator=(list &&other) {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            _size = other._size;
            other.head = other.tail = nullptr;
            other._size = 0;
        }
        return *this;
    }

    // assign(count, value)
    void assign(int s, T val) {
        clear();
        for (int i = 0; i < s; i++)
           push_back(val);
    }

    // assign(initializer_list)
    void assign(initializer_list<T> l) {
        clear();
        for (auto it = l.begin(); it != l.end(); ++it)
             push_back(*it);
    }

    T& front() {
        if (!head) throw out_of_range("List is empty");
        return head->data;
    }

    T& back() {
        if (!tail) throw out_of_range("List is empty");
        return tail->data;
    }

    bool empty() {
 return head == nullptr; 
         }
    int size() {
  return _size;
        }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        _size = 0;
    }

    void resize(int n) {
        if (n < _size) {
            while (_size > n) pop_back();
        } else {
            while (_size < n) push_back(T());
        }
    }

    void remove(T val) {
        Node* t = head;
        while (t) {
            Node* next_node = t->next;
            if (t->data == val) {
                if (t->prev) t->prev->next = t->next;
                if (t->next) t->next->prev = t->prev;
                if (t == head) head = t->next;
                if (t == tail) tail = t->prev;
                delete t;
                _size--;
            }
            t = next_node;
        }
    }

    void push_back(T val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        _size++;
    }

    void pop_back() {
        if (!tail) return;
        Node* t = tail;
        if (head == tail) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete t;
        _size--;
    }

    iterator insert(iterator it, T val) {
        Node* current = it.get();
        Node* n = new Node(val);

        if (!current) {
            push_back(val);
            return iterator(tail);
        } else if (current == head) { 
            n->next = head;
            head->prev = n;
            head = n;
        } else { // insert in middle
            Node* prevNode = current->prev;
            prevNode->next = n;
            n->prev = prevNode;
            n->next = current;
            current->prev = n;
        }
        _size++;
        return iterator(n);
    }

    iterator erase(iterator it) {
        Node* t = it.get();
        if (!t) return iterator(nullptr);

        iterator ret(t->next);

        if (t == head) {
            head = t->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (t == tail) {
            tail = t->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } else {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }

        delete t;
        _size--;
        return ret;
    }
};

int main() {
    list<int> lst1;
    cout << "Created empty lisst \n" <<boolalpha<< (lst1.empty() ) << endl;

    list<int> lst2(5, 10);
    cout << "lst2 values: \n";
    for (auto it = lst2.begin(); it != lst2.end(); ++it) cout << *it << " ";
    cout << endl;

    list<int> lst3 = {1, 2, 3, 4, 5};
    cout << "lst3 aftre initialized \n";
    for (auto it = lst3.begin(); it != lst3.end(); ++it) cout << *it << " ";
    cout << endl;

    list<int> lst4(lst3);
    cout << "lst4 after copy of lst3: \n";
    for (auto it = lst4.begin(); it != lst4.end(); ++it) cout << *it << " ";
    cout << endl;

    list<int> lst5(std::move(lst4));
    cout << "lst5 after moved from lst4: \n";
    for (auto it = lst5.begin(); it != lst5.end(); ++it) cout << *it << " ";
    cout << endl;
    cout << "lst4 after move sis mepty \n " << boolalpha<<(lst4.empty())  << endl;

    lst1.push_back(100);
    lst1.push_back(200);
    lst1.push_back(300);
    cout << "lst1 after push_back \n";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) cout << *it << " ";
    cout << endl;

    // pop_back
    lst1.pop_back();
    cout << "lst1 after pop_back: \n";
    for (auto it = lst1.begin(); it != lst1.end(); ++it) cout << *it << " ";
    cout << endl;

    // insert
    auto it = lst1.begin(); ++it;
    lst1.insert(it, 150);
    cout << "lst1 after inserting of 150 \n";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) cout << *it2 << " ";
    cout << endl;

    // erase
    lst1.erase(lst1.begin());
    cout << "lst1 after erasing first element: ";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) cout << *it2 << " ";
    cout << endl;

    // assign
    lst1.assign(4, 7);
    cout << "lst1 after assign(4,7): \n";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) cout << *it2 << " ";
    cout << endl;

    lst1.assign({9, 8, 7, 6});
    cout << "lst1 after assign: \n";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) cout << *it2 << " ";
    cout << endl;

    cout << "Front of lst1: " << lst1.front() << ", Back of lst1: " << lst1.back() << endl;

    lst1.remove(7);
    cout << "lst1 after removing 7:\n ";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) cout << *it2 << " ";
    cout << endl;

    lst1.resize(6); // add default values
    cout << "lst1 after resize(6): \n";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) 
    cout << *it2 << " ";
    cout << endl;

    lst1.resize(3); // shrink
    cout << "lst1 after resize(3):\n ";
    for (auto it2 = lst1.begin(); it2 != lst1.end(); ++it2) 
      cout << *it2 << " ";
    cout << endl;

    lst2 = lst1;
    cout << "lst2 after copy assignment from lst1: \n";
    for (auto it2 = lst2.begin(); it2 != lst2.end(); ++it2) 
     cout << *it2 << " ";
    cout << endl;

    lst5 = std::move(lst2);
    cout << "lst5 after move assignment from lst2: \n";
    for (auto it2 = lst5.begin(); it2 != lst5.end(); ++it2)
   cout << *it2 << " ";
    cout << endl;
    cout << "lst2 after move assignment empty \n" << (lst2.empty()) << endl;

    lst5.clear();
    cout << "lst5 after clear, empty? \n" << (lst5.empty()) << endl;

    return 0;
}

