//GCD
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
          if(a==0)
                    return b;
          int k=gcd(b%a,a);
          return k;
}
int main()
{
          int a,b;
          cin>>a>>b;
          int k=gcd(a,b);
          cout<<k;
}
