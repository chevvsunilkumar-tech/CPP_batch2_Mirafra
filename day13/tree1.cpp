#include <iostream>

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) 
        : data(val), left(nullptr), right(nullptr) {}
};

// Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    // Go Left
    inorder(root->left); // &3

    // Print current node info
    std::cout << "Node Data: " << root->data
              << " | Address: " << root
              << " | Left: " << root->left
              << " | Right: " << root->right
              << std::endl;

    // Go Right
    inorder(root->right);
}

// Delete entire tree (Postorder)
void deleteTree(Node* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    std::cout << "Deleting Node: " << root->data
              << " | Address: " << root
              << std::endl;

    delete root;
}

int main()
{
    /*
            10
           /  \
          5    20
         / \     \
        3   7     30
    */

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right->right = new Node(30);

    std::cout << "\nInorder Traversal with Addresses:\n\n";
    inorder(root); //&10

    // std::cout << "\n\nDeleting Tree:\n\n";
    // deleteTree(root);

    return 0;
}

