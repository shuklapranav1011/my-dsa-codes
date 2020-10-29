
//Replace each node with sum of child nodes
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

int sumReplacement(node*root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return root->data;
    int ls=sumReplacement(root->left);
    int rs=sumReplacement(root->right);
    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
}

int main()
{
    node* root=buildTree();
    //cout<<diameterTree1(root);
    Pair p=fastdiameterTree(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
}