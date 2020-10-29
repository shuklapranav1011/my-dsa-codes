//Diameter of a tree is the longest distance between any two nodes of tree
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
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

//Approach 1
//O(n2)
int heightTree(node*root)
{
    if(root==NULL)
    return 0;
    int ls=heightTree(root->left);
    int rs=heightTree(root->right);
    return 1+max(ls,rs);
}

int diameterTree(node*root)
{
    if(root==NULL)
    return 0;
    int ls=heightTree(root->left);
    int rs=heightTree(root->right);
    int case1=ls+rs;
    int case2=diameterTree(root->left);
    int case3=diameterTree(root->right);
    return max(case1,max(case2,case3));
}
//


int main()
{
    node* root=buildTree();
    cout<<diameterTree(root);
}