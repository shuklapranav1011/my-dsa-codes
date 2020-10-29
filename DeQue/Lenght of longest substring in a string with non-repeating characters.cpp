#include <iostream>
#include <deque>
using namespace std;

int slider_window(char *in, int *pos)
{
   deque <char> q;
   int m=INT_MIN;
   int i=0,j;
   for(int i=0;in[i]!='\0';i++)
   {
      char x=in[i];
      pos[x-97]++;

      //expand window
         q.push_back(x);
      //contract window
       if(pos[x-97]>1)
         {
            //store length allowed
            j=q.size()-1;
            //now shrink window
            while(!q.empty() && pos[q.back()-97]>1)
            {
               pos[q.front()-97]--;
               q.pop_front();
            }
         }
         else
         {
            //store length allowed
             j=q.size();
         }
         m=max(m,j);
   }
   return m;
}
int main()
{
   int pos[26]={0};
   char in[100];
   cin>>in;
   int m=slider_window(in,pos);
   cout<<m;
}
