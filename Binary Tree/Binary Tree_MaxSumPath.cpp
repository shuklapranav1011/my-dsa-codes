//Max Sum Path from any node to any node in a given binary tree
#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
    int data;
    node*left;
    node*right;
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
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

class Pair
{
    public:
    int branchSum;
    int maxSum;
    Pair()
    {
        branchSum=0;
        maxSum=0;
    }
};
 Pair maxSumPath(node*root)
 {
    Pair p;
    if(root==NULL)
    return p;

    Pair left=maxSumPath(root->left);
    Pair right=maxSumPath(root->right);

    int op1=root->data;
    int op2=left.branchSum+root->data;
    int op3=right.branchSum+root->data;
    int op4=left.branchSum+right.branchSum+root->data;
    
    int curr_ans_through_root=max(op1,max(op2,max(op3,op4)));

    p.branchSum=max(left.branchSum,max(right.branchSum,0)) + root->data;
    p.maxSum=max(left.maxSum,max(right.maxSum,curr_ans_through_root));
    return p;
 }
 int main()
 {
     node*root=buildTree();
     Pair m=maxSumPath(root);
     cout<<m.maxSum;
 }