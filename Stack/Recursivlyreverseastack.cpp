#include <iostream>
#include <stack>
using namespace std;

void insertatbottom(stack <int> &s,x)
{
   if(s.empty())
   {
      s.push(x);
      return;
   }
   int y=s.top();
   s.pop();
   insertatbottom(s,x);
   s.push(y);
}

void revstack(stack <int> &s)
{
   if(s.empty())
   {
      return;
   }
   int x=s.top();
   s.pop();
   revstack(s);
   insertatbottom(s,x);
}

int main()
{
   stack <int> s;
}
