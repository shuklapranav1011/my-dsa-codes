#include <iostream>
using namespace std;
class Stack{
   queue q1;
   queue q2;

public:
   void push(int data)
   {
      if(!q2.empty())
      {
         q2.push(data);
         return;
      }
      q1.push(data);
      return;
   }
};

int main()
{

}
