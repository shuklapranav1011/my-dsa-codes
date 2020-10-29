#include <iostream>
using namespace std;
class node
{
public:
       int data;
       node* left;
       node* right;

       node(int d)
       {
              data=d;
              left=NULL;
              right=NULL;
       }
};

node* buildTree()
{
          int d;cin>>d;
          if(d==-1)
                return NULL;
          node* root=new node(d);
          root->left=buildTree();
          root->right=buildTree();
          return root;
}

void printPreorder(node*root)
{
    if(root=NULL)
    return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node*root)
{
    if(root==NULL)
    return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(node*root)
{
    if(root==NULL)
    return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

//Level Order Traversal
//first we need to find the height of the tree
int height(node* root)
{
    if(root==NULL)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    return max(h1,h2)+1;;
}

//printing all the levels
//function to print ith level
void printIthLevel(node* root,int curr_level)
{
    if(root==NULL)
    return;
    if(curr_level==1)
    cout<<root->data<<" ";
    printIthLevel(root->left,curr_level-1);
    printIthLevel(root->right,curr_level-1);
}

void printAllLevels(node* root)
{
    for(int h=1;h<=height(root);h++)
        {
            printIthLevel(root,h);
            cout<<endl;
        }
}
int main()
{
    node*root=buildTree();
    /*
    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    */
    printAllLevels(root);
}