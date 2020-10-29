//first non-repeating character
#include <iostream>
#include <queue>
using namespace std;
int main()
{
   queue <char> q;
   int pos[26]={0};
   char x;
   cin>>x;
   while(x!='/')
   {
      pos[x-97]++;
      q.push(x);
      while(pos[q.front()-97]>1)
      {
         char c=q.front();
         while(q.front()==c)
            q.pop();
         if(q.empty())
            break;
      }
      if(!q.empty())
         cout<<q.front()<<" ";
      else
         cout<<"-1 ";
      cin>>x;
   }
}
