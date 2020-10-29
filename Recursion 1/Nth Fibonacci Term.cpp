#include <iostream>
using namespace std;

int fibo(int a,int b,int n)
{
   if(n==0)
      return b;
   return fibo(a+b,a,n-1);
}

int main()
{
   int n;
   cin>>n;
   cout<<fibo(0,1,n);
}
