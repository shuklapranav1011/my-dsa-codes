#include <iostream>
using namespace std;

void printfactors(int n)
{
          int c;
          //agar koi prime nai aaya beech me to n==1 tak jayega
          for(int i=2;i*i<=n;i++) //taking 66 example.....when n=11. loop stops at 4
                    if(n%i==0)
                              while(n%i==0)
                               {
                                         cout<<i<<"x";
                                         n=n/i;
                               }
          if(n!=1)
                    cout<<n;
}
int main()
{
          int n;
          cin>>n;
          printfactors(n);
}
