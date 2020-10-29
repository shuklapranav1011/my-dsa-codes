//sorted in increasing order
#include <iostream>
using namespace std;
//we are having a single array over which we iterate by changing the address
bool check_sort(int *p,int n)
{
      if(p[0]>p[1])
         return false;
      if(n==0)
         return true;
      return check_sort(&p[1],n-1);
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   cout<<check_sort(a,n);
}
