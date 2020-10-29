#include <iostream>
using namespace std;

int _partition(int a[],int s,int e)
{

         //[2,7,8,6,1,5,4]
         int i=-1;
         int j=s;
         int pivot_ele=a[e];

         for(int j=s;j<=e-1;j++) //excluding pivot element therefore e-1
         {
            if(a[j]<=a[e])
            {
               i=i+1;
               swap(a[j],a[i]);
            }
            else
            {
               j=j+1;
            }
         }
         swap(a[i+1],a[e]);
         // [2,1,4,6,1,7,5,8]
         return i+1;
}

void qs(int a[],int s,int e)
{
   if(s>=e)
      return;

  int p= _partition(a,s,e);
   qs(a,s,p-1);
   qs(a,p+1,e);
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   qs(a,0,n-1);
}
