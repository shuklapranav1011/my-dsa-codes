//inversion count
//a[i]>a[j] && i<j  print pair(i,j)

#include <iostream>
#include <algorithm>
using namespace std;

int cross_inversions(int*a,int s,int e)
{
   int mid=(s+e)/2;
   int i=s;
   int j=mid+1;
   int k=s;
   int temp[100000];//to  sort the array
   int cnt=0;//to count number of pairs

   while(i<=mid & j<=e)
   {
      if(a[i]<=a[j])
         temp[k++]=a[i++];
      else
      {
         temp[k++]=a[j++];
         cnt=mid-i+1;
      }
   }
   while(i<=mid)
      temp[k++]=a[i++];
   while(j<=e)
      temp[k++]=a[j++];

   for(int i=s;i<=e;i++)
         a[i]=temp[i];

   return cnt;
}

int inversion_count(int *a,int s,int e)
{
   if(s>=e)
      return 0;
   int mid=(s+e)/2;
   int x=inversion_count(a,s,mid);
   int y=inversion_count(a,mid+1,e);
   int z=cross_inversions(a,s,e);

   return x+y+z;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
  cout<<inversion_count(a,0,n-1);
   return 0;
}
