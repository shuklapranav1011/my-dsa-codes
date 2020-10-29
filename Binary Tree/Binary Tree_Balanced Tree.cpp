#include <iostream>
#include <math.h>
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
//Method 1- Self Done
/*
int h1=0,h2=0,flag=1;
int isBalanced(node*root)
 {
     if(root==NULL)
     return 0;
     if(root->left==NULL)
     return h1+1;
     if(root->right==NULL)
     return h2+1;
     h1=isBalanced(root->left);
     h2=isBalanced(root->right);
     if(h1-h2 >=1)
        {
            flag=0;
            return 0;
        }
    return 0;
 }
*/
//

//Method 2
class HBPair
{
    public:
    int height;
    bool balance;
};

HBPair isBalanced(node*root)
{
    HBPair p;
    if(root==NULL)
    {
        p.height=0;
        p.balance=true;
    }

    HBPair left=isBalanced(root->left);
    HBPair right=isBalanced(root->right);
    p.height=max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance)
    p.balance=true;
    else
    p.balance=false;

    return p;
}
int main()
{
     node*root=buildTree();
     pair P=isBalanced(root);
     /*if(flag==1)
     {
         cout<<"Balanced";
         return 0;
     }
    cout<<"Not Balanced";
    return 0;
    */
    if(isBalanced(root).balance)
    cout<<"Balanced";
    else
    cout<<"Not Balanced";
}