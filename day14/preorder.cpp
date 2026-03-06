#include <iostream>
#include <stack>

// --------------------
// Node Definition
// --------------------
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// --------------------
// BST Insert Function
// --------------------
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

// --------------------
// Recursive Preorder
// Root → Left → Right
// --------------------
void preorder_recursive(Node* root)
{
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

// --------------------
// Iterative Preorder
// Using Stack
// --------------------
void preorder_iterative(Node* root)
{
    if (!root) return;

    std::stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        Node* current = st.top();
        st.pop();

        std::cout << current->data << " ";

        // Push right first (so left is processed first)
        if (current->right)
            st.push(current->right);

        if (current->left)
            st.push(current->left);
    }
}

// --------------------
// Delete Tree (Postorder)
// --------------------
void deleteTree(Node* root)
{
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// --------------------
// Main Function
// --------------------
int main()
{
    Node* root = nullptr;

    // Insert elements into BST
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values)
        root = insert(root, val);

    std::cout << "Recursive Preorder Traversal:\n";
    preorder_recursive(root);

    std::cout << "\n\nIterative Preorder Traversal:\n";
    preorder_iterative(root);

    // Cleanup memory
    deleteTree(root);

    return 0;
}

