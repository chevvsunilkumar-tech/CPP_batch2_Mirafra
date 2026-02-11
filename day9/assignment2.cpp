#include <iostream>
using namespace std;

class forward_list
{
private:
    int data;
    forward_list *next;
     forward_list *head;
public:
    forward_list(int val)
    {
        data = val;
        next = NULL;
    }

    void addBegin(int val)
    {
        forward_list *n = new forward_list(val);
        n->next = head;
        head = n;
    }

    void addEnd(int val)
    {
        forward_list *n = new forward_list(val);
        if (!head)
        {
            head = n;
            return;
        }
        forward_list *t = head;
        while (t->next)
            t = t->next;
        t->next = n;
    }

    void addMiddle(int val, int pos)
    {
        if (pos <= 0 || !head)
        {
            addBegin(val);
            return;
        }
        forward_list *t = head;
        for (int i = 1; i < pos && t->next; i++)
            t = t->next;
        forward_list *n = new forward_list(val);
        n->next = t->next;
        t->next = n;
    }

    void deleteBegin()
    {
        if (!head)
            return;
        forward_list *t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        forward_list *t = head;
        while (t->next->next)
            t = t->next;
        delete t->next;
        t->next = NULL;
    }

    void deleteMiddle(int pos)
    {
        if (pos <= 0 || !head || !head->next)
        {
            deleteBegin();
            return;
        }
        forward_list *t = head;
        for (int i = 1; i < pos && t->next->next; i++)
            t = t->next;
        forward_list *d = t->next;
        t->next = d->next;
        delete d;
    }

    int count()
    {
        int c = 0;
        forward_list *t = head;
        while (t)
        {
            c++;
            t = t->next;
        }
        return c;
    }

    void print()
    {
        forward_list *t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    void reverse()
    {
        forward_list *p = NULL, *c = head, *n = NULL;
        while (c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
    }
};

//forward_list *forward_list::head = NULL;

int main()
{
    forward_list list(0);

    list.addBegin(10);
    list.addEnd(20);
    list.addEnd(30);
    list.addMiddle(15, 1);
    list.print();

    list.deleteBegin();
    list.deleteEnd();
    list.print();

    list.addEnd(40);
    list.addEnd(50);
    list.print();

    list.reverse();
    list.print();

    cout << list.count() << endl;

    return 0;
}

