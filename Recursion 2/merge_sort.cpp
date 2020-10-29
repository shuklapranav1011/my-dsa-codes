#include <iostream>
using namespace std;

void _merge(int *a,int s,int e)
{
   int temp[1000000];
   int mid=(s+e)>>1;
   int i=s;
   int j=mid+1;
   int k=s;
   while(i<=mid && j<=e)
   {
      if(a[i]<a[j])
         temp[k++]=a[i++];
         else
            temp[k++]=a[j++];
   }
   while(i<=mid)
      temp[k++]=a[i++];
   while(j<=e)
      temp[k++]=a[j++];

   for(int i=s;i<=e;i++)
      a[i]=temp[i];
}

void merge_sort(int *a,int s,int e)
{
   if(s>=e)
      return;
    int mid=(s+e)>>1;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    _merge(a,s,e);
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   return 0;
}
