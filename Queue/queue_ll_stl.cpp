#include <iostream>
#include <list>
using namespace std;

class Queue
{
   list q;
   void push(int data)
   {
         q.push_back(data);
   }

   void pop()
   {
      if(q.isEmpty())
      {
         cout<<"Queue is empty"<<endl;
         return;
      }
      q.pop_front();
   }

   void top()
   {
      cout<<*q.begin()<<endl;
   }
};

int main()
{

}
