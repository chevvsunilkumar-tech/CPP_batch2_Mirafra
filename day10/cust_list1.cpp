#include <iostream>
#include <memory>
using namespace std;
class LinkedList
{
private:
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;

        Node(int value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void push_front(int value)
    {
        auto newNode = std::make_unique<Node>(value);

        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    void print() const
    {
        Node* temp = head.get();

        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next.get();
        }
        std::cout << "\n";
    }
  int  front()
{
return head->data;

}

void push_back(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        head = std::move(newNode);
        return;
    }

    Node* current = head.get();
    while (current->next) {
        current = current->next.get(); 
    }

    current->next = std::move(newNode);
}

void pop_back()
{
if(head!=nullptr)
{




}

}




};
int main()
{
    LinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.print();

    return 0;
}

