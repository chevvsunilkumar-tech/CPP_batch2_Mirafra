#include <iostream>
#include <memory>
#include <optional>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(int value) : data(value) {}
    };

    std::unique_ptr<Node> root;

public:
    // Insert
    void insert(int value)
    {
        insertImpl(root, value); //BST
    }

    // Search
    bool search(int value) const
    {
        return searchImpl(root.get(), value);
    }


    // Inorder Traversal
    void traversal() const
    {
        inorderImpl(root.get());
        std::cout << "\n";
    }
    void delete_node(int val)
     { 
   delete_node_implem(root,val);
     
     }

  

private:
    // Insert Implementation
    void insertImpl(std::unique_ptr<Node>& node, int value)
    {
        if (!node)
        {
            node = std::make_unique<Node>(value);
            return;
        }

        if (value < node->data)
            insertImpl(node->left, value);
        else if (value > node->data)
            insertImpl(node->right, value);
    }

    // Search Implementation
    bool searchImpl(const Node* node, int value) const
    {
        if (!node) return false;

        if (value == node->data)
            return true;
        else if (value < node->data)
            return searchImpl(node->left.get(), value);
        else
            return searchImpl(node->right.get(), value);
    }

    

    void inorderImpl(const Node* node) const
    {
        if (!node) 
         return;

        inorderImpl(node->left.get());
        std::cout << node->data << " ";
        inorderImpl(node->right.get());
    }
void delete_node_implem(std::unique_ptr<Node>& root, int val)
{
    if (!root)
        return;

    if (val < root->data)
        delete_node_implem(root->left, val);

    else if (val > root->data)
        delete_node_implem(root->right, val);

    else  
    {
        // Case 1 No children
        if (!root->left && !root->right)
        {
            root.reset();
        }
        // Case 2 One child
        else if (!root->left)
        {
            root = std::move(root->right);
        }
        else if (!root->right)
        {
            root = std::move(root->left);
        }
        // Case 3 Two children
        else
        {
            /*Node* min = root->right.get();   //raw pointer
            while (min->left)
                min = min->left.get();

            root->data = min->data;      //min->data is smallest element in right subtree or inorder successor

            delete_node_implem(root->right, min->data);  //this to delete duplicate element
            */
            
              Node* max = root->left.get();   //raw pointer
            while (max->right)
                max = max->right.get();

            root->data = max->data;      //man->data is largest element in left subtree or inorder preccZedent

            delete_node_implem(root->left, max->data);  //this to delete duplicate element
            
            
            
        }
    }
}


};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Traversal: ";
    tree.traversal();

    std::cout << "Search 40: " << (tree.search(40) ? "Found\n" : "Not Found\n");
    
    cout<<"after deleteting 40 traversal \n";
    tree.delete_node(40);
     tree.traversal();
    

     

    return 0;
}

