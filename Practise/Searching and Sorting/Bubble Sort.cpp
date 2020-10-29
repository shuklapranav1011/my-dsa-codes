#include <iostream>
using namespace std;
int main()
{
   int a[100];
   for(int i=0;i<=7;i++)
      {
         cin>>a[i];
      }


   for(int i=0;i<7;i++)
   {
      for(int j=0;j<7-i-1;j++)
      {
         if(a[j]>=a[j+1])
            swap(a[j],a[j+1]);
      }
   }
}
