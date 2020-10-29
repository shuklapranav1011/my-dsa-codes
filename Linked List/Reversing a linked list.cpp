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


void reverseList(node*&head)
{
   if(head==NULL|| head->next==NULL)
      return;

   node*c=head;
   node*p=NULL;
   node*n;

   while(c!=NULL)
   {
      //save the next node
      n=c->next;
      //make current node point to previous
      c->next=p;
      //update p&c
      p=c;
      c=n;
   }
   head=p;
   return;
}


//RUNNER TECHNIQUE
//runner technique is using only single pass to iterate the linked list
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


int main()
{
   node*head=NULL;
   /*
   insertAtHead(head,3);
   insertAtHead(head,4);
   insertAtHead(head,9);
   insertAtTail(head,10);
   insertAtTail(head,11);
   insertAtMiddle(head,13,3);
    print(head);https://www.deshawindia.com/OpenPositions.shtml
   deleteHead(head);
   print(head);
   deleteTail(head);
   print(head);
   deleteAtMiddle(head,3);
    print(head);
    */
  cin>>head; //cascading of operators
  //  inputList(head);
   // inputList(head1);
   // print(head);
   cout<<head; //this prints the whole linked list
   reverseList(head);
   cout<<head;
   node*mid=midpointList(head);
   node*kth=kth_node_from_end(head,5);
   cout<<endl<<kth->data<<endl;
}




