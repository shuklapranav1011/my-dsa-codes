//greatest number which divides two number
//brute force is to run form 1 to min(a,b) and check which number divides both

//Rules GCD(a,b)=GCD(b,a%b) and GCD of (a,0)=a
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
   return b==0?a:gcd(b,a%b);
}
int main()
{
   int a,b;
   cin>>a>>b;
   cout<<gcd(a,b);
}
