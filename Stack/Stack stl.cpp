#include <stack>
#include <iostream>
using namespace std;

int main()
{
   stack <int> s;
   s.push(10);
   s.pop(); //this function does not print a value
   s.push(10);
   s.push(26);
   for(int i=1;i<=11;i++)
   {
      s.push(i);
   }

   while(!s.empty())
      {
         cout<<s.top()<<endl;
         s.pop();
      }
   }
