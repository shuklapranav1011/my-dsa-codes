#include <iostream>
using namespace std;

int canbeat(int h,int p)
{
   if(p==0 && h>0)
      return 0;
   if(h<=0 && p>=0)
      return 1;
   int t=canbeat(h-p,p>>1);
   return t;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   int h,p;
   cin>>h>>p;
   cout<<canbeat(h,p)<<endl;
   }
}


