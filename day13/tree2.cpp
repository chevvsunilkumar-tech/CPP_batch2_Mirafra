#include <iostream>
using namespace std;

struct Node
{
    
    int data;
    Node *left;
    Node *right;
    Node(int d):data(d),left(nullptr),right(nullptr)
    {
        
        
        
    }
    
  
    
};

  void inorder(Node *root)
    {     if(root==nullptr)
            return;
        inorder(root->left);
        cout<<"address of node :"<<root<<" "<<root->data<<"\n";
        inorder(root->right);        
    }
    
    Node * insert(Node *&root,int val)
    {
        if(root==nullptr)
        {
            
            root=new Node(val);
            return root;
        }
        if(root->data>val)
        insert(root->left,val);
        else
        insert(root->right,val);
    return root;
        
    }
    void delete_all_node(Node *root)
    {
     if(root==nullptr)
     return;
     delete_all_node(root->left);
     delete_all_node(root->right);
  cout<<root->data<<" is getting delteted\n";   
     delete root;
     
      }


bool search(Node *root,int val)
{
if(root==nullptr)
{
return false;
}

        if(root->data>val)
       return  search(root->left,val);
        else if(root->data<val)
        return search(root->right,val);
          else
            return true;
        
       return false;

}



int main()
{    Node *root=nullptr;

   root=  insert(root,10);
    root= insert(root,6);
    root= insert(root,22);
    root= insert(root,8);
    root= insert(root,12);
   root=  insert(root,11);
 
     inorder(root);

   if(search(root,12))
  cout<<"present\n";
   else
   cout<<"not present\n";

  delete_all_node(root);
        
    
}
