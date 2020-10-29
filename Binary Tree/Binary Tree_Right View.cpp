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

//Approach 1 using bfs
/*
void bfsnrightview(node*root)
{
    queue <node*> q;
    vector <int> rv;
    q.push(root);
    q.push(NULL);
    rv.push_back(root->data);
    rv.push_back(-1);
    while(!q.empty())
    {   
        node*f=q.front();
        if(f==NULL)
        {
           cout<<endl;
           q.pop();
           if(!q.empty())
           {
               q.push(NULL);
               rv.push_back(-1);
           }
        }
        else
        {
            node*temp=f;
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            {
                rv.push_back(f->left->data);
                q.push(f->left);
            }
            if(f->right)
            {
                rv.push_back(f->right->data);
                q.push(f->right);
            }
         }
     }
    cout<<endl;
    int i=0;
    while(i!=rv.size())
    {
        if(rv[i]==-1)
        cout<<rv[i-1]<<endl;
        i++;
    }
}
*/

//Approach 2

void rightview(node*root,int curr_level)
{
    if(root==NULL)
    return;
    static int max_level=-1;
    if(curr_level>max_level)
    {
        cout<<root->data<<endl;
        max_level=curr_level;
    }
    rightview(root->right,curr_level+1);
    rightview(root->left,curr_level+1);
}
int main()
{
    node*root=buildTree();
    rightview(root,0);
}