#include <iostream>
using namespace std;
class node
{
   public:
   int data;
   node*next;

   node(int d)
   {
      data=d;
      next=NULL;
   }
};


void print(node*head)
{
   while(head!=NULL)
   {
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}

ostream& operator<<(ostream &os,node*head)
{
   print(head);
   return os;
}

void insertAtHead(node*&head,int data)
{
   if(head==NULL)
    {
       head=new node(data);
      return;
    }
   node*n=new node(data);
   n->next=head;
   head=n;
   return;
}

void insertAtTail(node*head,int data)
{
   if(head==NULL)
     {
        insertAtHead(head,data);
        return;
     }
   while(head->next!=NULL)
   {
      head=head->next;
   }
   node*n=new node(data);
   head->next=n;
}

int len_list(node*head)
{
   int cnt=0;
   while(head!=NULL)
   {
      cnt++;
      head=head->next;
   }
   return cnt;
}

void inputList(node*&head)
{
   int in;
   cin>>in;
   while(in!=-1)
   {
      insertAtHead(head,in);
      cin>>in;
   }
   return;
}

istream& operator>>(istream &is,node*head)
{
   inputList(head);
   return is;
}

node* mergeList(node*a, node*b)
{
   if(a==NULL)
      return a;
   if(b==NULL)
      return b;

   node*c;
   if(a->data < b->data)
   {
      c=a;
      c->next=mergeList(a->next,b);
   }
   else
   {
      c=b;
      c->next=mergeList(a,b->next);
   }
   return c;
}


int main()
{
   node* head1=NULL;
   node* head2=NULL;
   cin>>head1>>head2;
   cout<<head1<<head2;

   node*n=mergeList(head1,head2);
   cout<<n;

}



























































