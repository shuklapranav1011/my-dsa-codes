#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
   stack <int> s;
   for(int i=1;i<=5;i++)
      s.push(i);
   stack <int> s1;
   swap(s1,s);
  while(!s1.empty())
  {
     s.push(s1.top());
     s1.pop();
  }
  while(!s.empty())
  {
     cout<<s.top()<<endl;
     s.pop();
  }
}
