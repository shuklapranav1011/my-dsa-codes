//count binary strings of length n which have no consecutive ones

#include <iostream>
#include <string>
using namespace std;


int f(int n)
{
   if(n<=0)
      return 1;
   if(n==1)
      return 2;
   return f(n-1)+f(n-2);
}

int main()
{
   int n;
   cin>>n;
   cout<<f(n);
}
