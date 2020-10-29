#include <iostream>

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

 void insertAthead(node&head,int data)
 {
      node*n=new node(data);
      node*temp=head;
      if(temp!=NULL)
      {
         while(temp->next!=head)
                  temp=temp->next;

         temp->next=n;
         n->next=head;
         head=n;
      }
      else
      {
         n->next=n;
      }
 }

 void print(node*head)
 {
         node*n=head;
         while(head->next!=n)
         {
            cout<<head->data<<"->";
            head=head->next;
         }
         cout<<head->data<<"->";
 }

 int main()
 {
    std::cout<<"Circular Linked List";
 }
