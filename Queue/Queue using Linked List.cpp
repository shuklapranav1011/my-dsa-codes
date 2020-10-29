#include <iostream>
using namespace std;

class Node
{
   public:
   Node *next;
   int data;

   Node(int d)
   {
      data=d;
      next=NULL;
   }
};

class Queue
{
   int *f;
   int *r;

   Queue()
   {
      f=r=NULL;
   }

   void push(int data)
   {
      Node* n=new Node(data);
      if(r==NULL)
      {
         f=r=n;
         return;
      }

      r->next=n;
      r=n;
   }

   void pop()
   {
      if(f==NULL)
         return;

      Node*n=f;
      f=f->next;
      if(f==NULL)
         r=NULL;

      delete n;
   }
};
