#include <iostream>
#include <queue>
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
        right-NULL;
    }
};

node* buildTreefromPreOrdernInOrder(int *pre,int *ino,int s,int e)
{   
    if(s>e)
    return NULL;
    static int i=0;
    int j;
    for(j=s;j<=e;j++)
    if(ino[j]==pre[i])
    break;
    i++;
    node*root=new node(pre[s]);
    root->left=buildTreefromPreOrdernInOrder(pre,ino,s,j-1);
    root->right=buildTreefromPreOrdernInOrder(pre,ino,j+1,e);
    return root;
}

void bfs(node*root)
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
int main() 
{   
    int pre[]={1,2,3,4,8,5,6,7};
    int ino[]={3,2,4,8,1,6,7,5};
    node* root=buildTreefromPreOrdernInOrder(pre,ino,0,7);
    bfs(root);
}
