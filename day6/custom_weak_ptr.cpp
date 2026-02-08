#include <iostream>
using namespace std;

struct control_b
{
    int* strong_c;
    int weak_c;

    control_b(int* s) : strong_c(s), weak_c(0)
    {
cout<<"control block constructor\n";
    }
   
   ~ control_b() 
    {
   cout<<"control block destructor\n";
    }
};

class sharedptr
{
public:
    int* data;
    int* count;
    control_b* cp;

    sharedptr(int d = 0)
    {
        data = new int(d);
        count = new int(1);
        cp = new control_b(count);
    }

    sharedptr(int* d, control_b* c)
    {
        data = d;
        cp = c;
        count = c->strong_c;
        (*count)++;
    }

    ~sharedptr()
    {
        if (count)
        {
            (*count)--;
            if (*count == 0)
            {
                delete data;
                if (cp->weak_c == 0)
                    delete cp;
                delete count;
            }
        }
    }

    sharedptr(const sharedptr& obj)
    {
        data = obj.data;
        count = obj.count;
        cp = obj.cp;
        (*count)++;
    }

    sharedptr& operator=(const sharedptr& obj)
    {
        if (this == &obj)
            return *this;

        data = obj.data;
        count = obj.count;
        cp = obj.cp;
        (*count)++;
        return *this;
    }

    sharedptr(sharedptr&& obj)
    {
        data = obj.data;
        count = obj.count;
        cp = obj.cp;
        obj.data = nullptr;
        obj.count = nullptr;
        obj.cp = nullptr;
    }

    sharedptr& operator=(sharedptr&& obj)
    {
        if (this == &obj)
            return *this;

        data = obj.data;
        count = obj.count;
        cp = obj.cp;
        obj.data = nullptr;
        obj.count = nullptr;
        obj.cp = nullptr;
        return *this;
    }
};

class weak_ptr
{
public:
    int* data;
    control_b* b;

    weak_ptr() : data(nullptr), b(nullptr)
    {
    }

    weak_ptr(sharedptr& p)
    {
        data = p.data;
        b = p.cp;
        b->weak_c++;
    }

    ~weak_ptr()
    {
        if (b)
        {
            b->weak_c--;
            if (*(b->strong_c) == 0 && b->weak_c == 0)
                delete b;
        }
    }

    weak_ptr(const weak_ptr& obj)
    {
        data = obj.data;
        b = obj.b;
        if (b)
            b->weak_c++;
    }

    weak_ptr& operator=(const weak_ptr& obj)
    {
        if (this == &obj)
            return *this;

        data = obj.data;
        b = obj.b;
        if (b)
            b->weak_c++;
        return *this;
    }

    weak_ptr(weak_ptr&& obj)
    {
        data = obj.data;
        b = obj.b;
        obj.data = nullptr;
        obj.b = nullptr;
    }

    weak_ptr& operator=(weak_ptr&& obj)
    {
        if (this == &obj)
            return *this;

        data = obj.data;
        b = obj.b;
        obj.data = nullptr;
        obj.b = nullptr;
        return *this;
    }

    sharedptr lock()
    {
        if (!b || *(b->strong_c) == 0)
            return sharedptr(0);

        return sharedptr(data, b);
    }

    bool expired()
    {
        return (!b) || *(b->strong_c) == 0;
    }

    int use_count()
    {
        if (!b)
            return 0;
        return *(b->strong_c);
    }
};
#include <iostream>
using namespace std;

int main()
{
    cout << "create sharedptr p1\n";
    sharedptr p1(10);
    cout << "use count p1: " << *p1.count << endl;

    cout << "\ncopy construct p2 from p1\n";
    sharedptr p2 = p1;
    cout << "use count p1: " << *p1.count << endl;

    cout << "\ncopy assign p3 from p1\n";
    sharedptr p3;
    p3 = p1;
    cout << "use count p1: " << *p1.count << endl;

    cout << "\nmove construct p4 from p3\n";
    sharedptr p4 = std::move(p3);
    cout << "use count p1: " << *p1.count << endl;

    cout << "\ncreate weak_ptr w1 from p1\n";
    weak_ptr w1(p1);
    cout << "weak use_count: " << w1.use_count() << endl;
    cout << "expired: " << w1.expired() << endl;

    cout << "\ncopy weak_ptr w2 from w1\n";
    weak_ptr w2 = w1;
    cout << "weak use_count: " << w2.use_count() << endl;

    cout << "\nmove weak_ptr w3 from w2\n";
    weak_ptr w3 = std::move(w2);
    cout << "weak use_count: " << w3.use_count() << endl;

    cout << "\nlock weak_ptr to get sharedptr p5\n";
    sharedptr p5 = w1.lock();
    cout << "use count p1: " << *p1.count << endl;

    cout << "\ndestroy p1, p2, p4, p5\n";
    {
        sharedptr t1 = p1;
        sharedptr t2 = p2;
    }

    cout << "before leaving scope\n";

    cout << "\nend of main\n";
    return 0;
}

