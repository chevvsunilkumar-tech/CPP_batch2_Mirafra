#include <iostream>
#include <memory>
#include <queue>

using namespace std;

struct car
{
    string mod;
    bool state;

    explicit car(string s = "", bool b = false)
        : mod(s), state(b) {}

    string status()
    {
    if(state)
    return "enable";
    else
    return "disable"; 
    }   
      
    friend ostream& operator<<(ostream& out,  car& node)
    {
         
        out << "mod name:" << node.mod<<boolalpha << " & state:" << node.status();
        out<<endl;
        return out;
    }
};

struct Node
{
    car data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    

    explicit Node(const car& d) : data(d) {}
};

void level_order(Node* root)
{
    if (root == nullptr)
        return;

    queue< Node*> q;
    q.push(root);

    while (!q.empty())
    {
         Node* cur = q.front();
        q.pop();
             cur->data.state=true;
        cout << cur->data;

        if (cur->left)
            q.push(cur->left.get());

        if (cur->right)
            q.push(cur->right.get());
    }
}

int main()
{
    unique_ptr<Node> root;

    root = make_unique<Node>(car("ecu"));
    root->left = make_unique<Node>(car("dash_board sytem "));
    root->right = make_unique<Node>(car("safety system"));

    root->left->left = make_unique<Node>(car("speed sensor"));
    root->left->right = make_unique<Node>(car("fuel sensor"));
    root->right->left = make_unique<Node>(car("airbag senosr"));
    root->right->right = make_unique<Node>(car("lock sensor"));
    
    
    /*    ecu
          /\
       dash safety
       /\      /    \
  speed  fuel airbag lock 
  
  */
    cout << "level order traversal:\n";
    level_order(root.get());
   cout<<"\n";

    return 0;
}
