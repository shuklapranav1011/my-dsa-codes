#include <iostream>
#include <stack>
using namespace std;

void ins(stack <int> &s,int val,int &m)
{
   if(val>=m)
      {
         s.push(val);
         return;
      }
   m=val;
   s.push(2*val-m);
   return;
}

void del(stack <int> &s,int &m)
{
   if(s.top()>=m)
   {
      s.pop();
      return;
   }
   m= 2*m -s.top();
   s.pop();
   return;
}

int main()
{
   stack <int> s;
   int m=INT_MAX;
   for(int i=1;i<=5;i++)
   {
      int n;
      cin>>n;
      ins(s,n,m);
   }

   del(s,m);
   cout<<m;
}
