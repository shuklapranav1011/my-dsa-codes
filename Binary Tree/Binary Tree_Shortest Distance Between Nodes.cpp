// shortest distance between two nodes

//Approach 
//find LCA
//find path of a from LCA and Path of 3b from LCA
//Ans = path1+path2
#include <iostream>
#include <queue>
#include <vector>
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

void bfs(node* root)
{   
    if(root==NULL)
    return;
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
    }
}

node* lca(node*root,int a,int b)
{
    if(root==NULL)
    return NULL;

    if(root->data==a || root->data==b)
    return root;

    node* isLeft=lca(root->left,a,b);
    node* isRight=lca(root->right,a,b);

    if(isLeft!=NULL && isRight!=NULL)
    return root;

    if(isLeft!=NULL)
    return isLeft;
    return isRight;
}

bool hasPath(node*root,vector <int>& path,int target)
{
    if(root==NULL)
    return false;

    path.push_back(root->data);
    if(root->data==target)
    return true;;

    if(hasPath(root->left,path,target) || hasPath(root->right,path,target))
    return true;

    path.pop_back();
    return false;
}

int main()
{
    node*root=buildTree();
    bfs(root);
    cout<<endl;
    int a,b;
    //cin>>a>>b;
    a=3,b=10;
    node*l=lca(root,a,b);
    cout<< "LCA is "<<l->data;
    cout<<endl;
    vector<int> path1,path2;
    if(hasPath(l,path1,a) && hasPath(l,path2,b))
    {
       for(auto x=path1.end()-1;x>=path1.begin();x--)
        cout<<*x<<" ";
       for(auto x=path2.begin()+1;x<path2.end();x++)
        cout<<*x<<" ";
    }
}