//Calculate span of stock price for days
#include <iostream>
using namespace std;

int span(int *a,int i)
{
   int k=0;
   for(int j=0;j<=i;j++)
   {
      int x=a[j];
      if(x<=a[i])
        k++;
      else
      {
         k=0;
      }
   }
   return k;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i]; //stock size for each day
   for(int i=0;i<n;i++)
   {
      cout<<span(a,i)<<" ";
   }
   cout<<"END";
}
