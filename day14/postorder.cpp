#include <iostream>
#include <stack>

// ---------------------------
// Node Definition
// ---------------------------
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ---------------------------
// BST Insert Function
// ---------------------------
Node* insert(Node* root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// ---------------------------
// Recursive Postorder
// Left → Right → Root
// ---------------------------
void postorder_recursive(Node* root)
{
    if (root == nullptr)
        return;

    postorder_recursive(root->left);
    postorder_recursive(root->right);
    std::cout << root->data << " ";
}

// ---------------------------
// Iterative Postorder
// Using Two Stacks
// ---------------------------
void postorder_iterative(Node* root)
{
    if (!root) return;

    std::stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);

        if (current->right)
            st1.push(current->right);
    }

    while (!st2.empty())
    {
        std::cout << st2.top()->data << " ";
        st2.pop();
    }
}

// ---------------------------
// Delete Tree (Postorder Logic)
// ---------------------------
void deleteTree(Node* root)
{
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ---------------------------
// Main Function
// ---------------------------
int main()
{
    Node* root = nullptr;

    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values)
        root = insert(root, val);

    std::cout << "Recursive Postorder Traversal:\n";
    postorder_recursive(root);

    std::cout << "\n\nIterative Postorder Traversal:\n";
    postorder_iterative(root);

    // Cleanup memory
    deleteTree(root);

    return 0;
}

