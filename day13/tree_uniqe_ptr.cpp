
//tree with unique ptr;

#include <iostream>
#include <memory>
#include<optional>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

void insert(unique_ptr<Node>& root, int val) {
    if (!root) {
        root = make_unique<Node>(val);
        return;
    }
    if (val < root->data)
        insert(root->left, val);
    else
        insert(root->right, val);
}

void inorder(unique_ptr<Node>& root) {
    if (!root) return;
    inorder(root->left);
    cout << "node:" << root->data << "\n";
    inorder(root->right);
}

optional<int> search(Node* root, int val)  {
    if (!root) return nullopt;
    if (val == root->data) return root->data;
    if (val < root->data)
        return search(root->left.get(), val);
    else
        return search(root->right.get(), val);
}

int main() {
    unique_ptr<Node> root;

    insert(root, 10);
    insert(root, 6);

    insert(root, 22);

    insert(root, 8);

    insert(root, 12);
    insert(root, 11);

    inorder(root);

    if (auto it=search(root.get(), 12))
        cout <<*it<< "present\n";
    else
        cout << "not present\n";

}

