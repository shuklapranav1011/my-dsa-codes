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
}

void print(node*head)
{
   while(head!=NULL)
   {
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
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


void insertAtMiddle(node*head,int data,int pos)
{
    if(head==NULL||pos==0)
      insertAtHead(head,data);
   else if(pos>=len_list(head))
      insertAtTail(head,data);
   else
   {
      int c=1;//we are beginning at start
      while(c<pos)
      {
         head=head->next;
         c++;
      }
      node*n=new node(data);
      n->next=head->next;
      head->next=n;
   }
}

void deleteHead(node*&head)
{
   if(head==NULL)
      return;
   node*n=new node(head->data);
   head=head->next;
   delete n;
}

void deleteTail(node*head)
{
   if(head==NULL)
      return;
   if(head->next==NULL)
   {
      delete head;
      head=NULL;
      return;
   }
   node*prev;
   node*temp=head;
   while(head->next!=NULL)
   {
      prev=temp;
      temp=head->next;
      head=head->next;
   }
   prev->next=NULL;
   delete temp;
}

void deleteAtMiddle(node*head,int pos)
{
   if(head==NULL||pos==0)
      {
         deleteHead(head);
         return;
      }
   if(pos>=len_list(head))
      {
         deleteTail(head);
         return;
      }

   int c=1;//we are beginning at start
   node*prev;
   node*temp=head;
      while(c<pos)
      {
         prev=temp;
         temp=head->next;
         head=head->next;
         c++;
      }
      prev->next=temp->next;
      temp->next=NULL;
      delete temp;
}


//Linear Search
//Even if it is a sorted Linked List we perform linear search

bool serachList(node*head,int ele)
{
   int cnt=1;
   while(head!=NULL)
      {
         if(head->data==ele)
         {
            cout<<"found at position = "<<cnt<<endl;
            cout<<"found at position = "<<cnt<<endl;
            return true;
         }
         cnt++;
      }
      return false;
}

bool searchList_Recursive(node*head,int ele)
{
   if(head==NULL)
      return false;
   if(head->data==ele)
      return true;
   searchList_Recursive(head->next,ele);
}

void inputList(node*&head)
{
   int d;
   cin>>d;
   while(d!=-1)
   {
      insertAtHead(head,d);
      cin>>d;
   }
   return;
}

//operator overloading
//cascading of operators
ostream& operator<<(ostream &os,node*head)
{
   print(head);
   return os;
}

istream& operator>>(istream&os,node*&head)
{
   inputList(head);
   return os;
}

node*midpointList(node*head)
{
   if(head==NULL or head->next==NULL)
      return head;
   node*fast=head;
   node*slow=head;
   while(fast!=NULL && fast->next!=NULL)
   {
      fast=fast->next->next;
      slow=slow->next;
   }
   return slow;
}

node*kth_node_from_end(node*head,int k)
{
   int cnt=0;
   node*fast=head;
   node*slow=head;
   while(cnt!=k)
   {
      fast=fast->next;
      cnt++;
   }
   while(fast!=NULL)
   {
      fast=fast->next;
      slow=slow->next;
   }
   return slow;
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


//sort an unsorted Linked List using merge sort
node* mergesortList(node*head)
{
   if(head==NULL ||head->next==NULL)
      return head;

   node*mid=
}



int main()
{
   node*head=NULL;
   node*head1=NULL;
   /*
   insertAtHead(head,3);
   insertAtHead(head,4);
   insertAtHead(head,9);
   insertAtTail(head,10);
   insertAtTail(head,11);
   insertAtMiddle(head,13,3);
    print(head);
   deleteHead(head);
   print(head);
   deleteTail(head);
   print(head);
   deleteAtMiddle(head,3);
    print(head);
    */

    //cascading of operators
  cin>>head>>head1;

  //  inputList(head);
   // inputList(head1);
   // print(head);

   cout<<head<<head1; //this prints the whole linked list
}



