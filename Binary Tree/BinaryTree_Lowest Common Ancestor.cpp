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
//Approach 1 Store path in a vector
/*
bool hasPath(node*root,vector <node*> path,int target)
{
    if(root==NULL)
    return false;
    path.push_back(root);
    if(root->data==target)
    return true;
    if(hasPath(root->left,path,target) || hasPath(root->right,path,target))
    return true;
    path.pop_back();
    return false;
}
*/

//Approach 2
//check if a lies of left of root and b lies on right the root is an LCA.
 /*
bool isPresent(node*root,int target)
{
    if(root==NULL)
    return false;
    if(target==root->data)
    return true;
    if(isPresent(root->left,target)||isPresent(root->right,target))
    return true;
    return false;
}
node* lca(node*root,int a,int b)
{
    //base
    if(root==NULL)
    return NULL;
    if(isPresent(root->left,a))
        if(isPresent(root->right,b))
            return root;
    if(isPresent(root->left,b))
        if(isPresent(root->right,a))
            return root;
    //recursive
    node* ans=lca(root->left,a,b);
    if(ans==NULL)
    ans=lca(root->right,a,b);
    return ans;
}
*/

node* lca(node*root,int a,int b)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==a || root->data==b)
    return root;
    
    node* isleft=lca(root->left,a,b);
    node* isright=lca(root->right,a,b);
    
    if(isleft!=NULL && isright!=NULL)
    return root;

    if(isleft!=NULL)
    return isleft;
return isright;
}

int main()
{
    node*root=buildTree();
    int a,b;
    cin>>a>>b;
    node* ans=lca(root,6,11);
    cout<<ans->data<<endl;
}