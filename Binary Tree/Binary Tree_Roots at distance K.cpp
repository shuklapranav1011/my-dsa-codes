//Nodes at distance K from the given target node
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

void printAtTargetK(node*root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
        cout<<root->data<<" ";
    printAtTargetK(root->left,k-1);
    printAtTargetK(root->right,k-1);
}

void pinTargetandprint(node*root,int target,int k)
{
    if(root==NULL||target==NULL)
    {
        return;
    }
    if(root->data==target)
    {
        cout<<"Target Set"<<endl;
        printAtTargetK(root,k);
    }
    pinTargetandprint(root->left,target,k);
    pinTargetandprint(root->right,target,k);
}


int main()
{
    node* root=buildTree();
    int target;
    cin>>target;
    pinTargetandprint(root,8,2);

}