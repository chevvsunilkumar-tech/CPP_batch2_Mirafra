#include <iostream>
#include <stack>
using namespace std;
// Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Iterative Inorder Traversal
/*void inorder(Node* root)
{
    std::stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty())
    {
        // Go to the leftmost node
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }

        // Visit node
        current = st.top();
        st.pop();

        std::cout << current->data << " ";

        // Go to right subtree
        current = current->right;
    }
}*/


void inorder(Node *root)
{
stack<Node *>st;
Node *curr=root;

while(curr!=nullptr ||!st.empty())
{


while(curr)
{
st.push(curr);
curr=curr->left;

}



curr=st.top();
st.pop();
cout<<curr->data<<" ";
curr=curr->right;


}


}

int main()
{
    // Creating the tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    std::cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}

