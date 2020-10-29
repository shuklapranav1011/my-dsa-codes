#include <iostream>
using namespace std;
int power(int a,int n)
{
   if(n==0)
      return 1;
   return a*power(a,n-1);
}

int fast_power(int a,int n)
{
   if(n==0)
      return 1;
   int i=fast_power(a*a,n>>1);
   if(n&1)
      return a*i;
   else
      return i;
}

int main()
{
   int a,n;
   cin>>a>>n;
   cout<<fast_power(a,n);
   return 0;
}
