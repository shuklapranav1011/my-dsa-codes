//technique to sort array when data lies in a certain range

#include <iostream>
#include <climits>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a[n]={0};
   int b[100000]={0};
   int maxi_pos=INT_MIN;
   int mini_pos=INT_MAX;

   for(int i=0;i<n;i++)
      {
         cin>>a[i];
         b[a[i]]++; //incrementing a[i]th position in b
         //finding range of b
         if(a[i]>=maxi_pos)
            maxi_pos=a[i];
         if(a[i]<=mini_pos)
            mini_pos=a[i];
      }

   int k=0;
   for(int i=mini_pos;i<=maxi_pos;i++)
   {
      while(b[i]>0)
         {
            a[k]=i;
            k++;
            b[i]--;
         }
   }

   for(auto x:a)
      cout<<x<<" ";
}
