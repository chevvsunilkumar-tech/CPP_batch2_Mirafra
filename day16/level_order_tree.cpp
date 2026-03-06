#include <iostream>
#include <memory>
#include <queue>

using namespace std;

struct Node
{
    int data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    explicit Node(int d) : data(d) {}
};

void insert(unique_ptr<Node>& root, int val)
{
    if (!root)
    {
        root = make_unique<Node>(val);
        return;
    }

    if (val < root->data)
        insert(root->left, val);
    else if (val > root->data)
        insert(root->right, val);
}

void level_order(const Node* root)
{
    if (root == nullptr)
        return;

    queue<const Node*> q;
    q.push(root);

    while (!q.empty())
    {
        const Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";

        if (cur->left)
            q.push(cur->left.get());

        if (cur->right)
            q.push(cur->right.get());
    }
}

int main()
{
    unique_ptr<Node> root;

   
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);
    
    /*    10
          /\
         5  15
        /\   /\ 
       3  7 12 18
       
       */
 
    cout << "Level Order Traversal: ";
    level_order(root.get());

    return 0;
}
