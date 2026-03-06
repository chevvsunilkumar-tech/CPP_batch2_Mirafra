#include <iostream>
#include <memory>
#include <string>

using namespace std;

class BST
{
private:

    struct car_details
    {
        string owner_name;
        int car_number;
        float rating;

        car_details(string name = "", int n = 0, float r = 0)
            : owner_name(name), car_number(n), rating(r)
        {
         }

        // Compare by rating
        bool operator<(const car_details& other) const
        {
            return rating < other.rating;
        }

        bool operator>(const car_details& other) const
        {
            return rating > other.rating;
        }

        bool operator==(const car_details& other) const
        {
            return rating == other.rating;
        }

        friend ostream& operator<<(ostream& o, const car_details& obj)
        {
            o << "Owner: " << obj.owner_name  << "  Car Number: " << obj.car_number  << "  Rating: " << obj.rating;
           cout<<"\n__________________________________________________________________________\n";

            return o;
        }
    };

    struct Node
    {
        car_details data;
        unique_ptr<Node> left;
        unique_ptr<Node> right;

        Node(car_details d) : data(d) {}
    };

    unique_ptr<Node> root;

public:

    void insert(const car_details& value)
    {
        insertImpl(root, value);
    }

    bool searchByRating(float rating) const
    {
        return searchImpl(root.get(), car_details("", 0, rating));
    }

    void traversal() const
    {
        inorderImpl(root.get());
        cout << "\n";
    }

   void remove(int val)
{
delete_node_implem(root,val);

}

private:

    void insertImpl(unique_ptr<Node>& node, const car_details& value)
    {
        if (!node)
        {
            node = make_unique<Node>(value);
            return;
        }

        if (value < node->data)
            insertImpl(node->left, value);
        else if (value > node->data)
            insertImpl(node->right, value);
    }

    bool searchImpl(const Node* node, const car_details& value) const
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
        if (!node) return;

        inorderImpl(node->left.get());
        cout << node->data << endl;
        inorderImpl(node->right.get());
    }

   void delete_node_implem(unique_ptr<Node>&root,int val)
{
    if(!root)
       return;
     else if(root->data>val)
         delete_node_implem(node->left,val);
     else if(root->data<val)
      delete_node_implem(node->right,val);
      else
   {
     if(!root->left &&!root->right)
      {
       root.reset();
   
//root=nullpt; also possible
       }
     else if(!root->right)
          root=move(root->left);
     else if(!root->left)
         root=move(root->right);

    else
     {
   Node *min=root.get();
   while(min->left)
   {
   min=(min->left).get();

    }
   root->data =min->data;

     delete_node_implem(node->right,min->data);

     }
   }
}


};

int main()
{
    BST tree;

    tree.insert({"sunil", 101, 4.5});
    tree.insert({"kridhna", 102, 3.8});
    tree.insert({"sirish", 103, 4.9});
    tree.insert({"David", 104, 2.5});
    tree.insert({"jag", 105, 4.2});

    cout << "cars sorted by rating\n";
    tree.traversal();

    cout << "\nSearch Rating 4.2 ";

       if(tree.searchByRating(4.2) )
           cout<<"present\n";
        else
         cout<<"not present\n";

    return 0;
}

