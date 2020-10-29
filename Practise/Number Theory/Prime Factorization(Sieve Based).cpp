//24 = 2x2x2x3
//using sieve method
#include <iostream>
#include <vector>
using namespace std;
vector<int> prime_sieve(int n)
{
   int a[n+1]={0};
   vector<int> primes;
   primes.reserve(n);
   primes.push_back(2);
   long long i,j;
   for(i=3;i<=n;i+=2)
      a[i]=1;
   for(i=3;i<=n;i+=2)
   {
      if(a[i]==1)
         {
            primes.push_back(i);
            for( j=i*i;j<=n;j=j+i)
            a[j]=0;
         }
   }
   //primes vector stores all the prime numbers till n
   return primes;
}
int main()
{
           long long n;
           cin>>n;
           vector<int> primes=prime_sieve(n);
           int i=0;
           int p=primes[0];
           while(p*p<=n) //agar n prime hua to p>root n ho jayega
           {
                     p=primes[i];
                     while(n%p==0)
                     {
                               cout<<p<<"x";
                               n=n/p;
                     }
                     i++;
           }
           if(n!=1)
                    cout<<n;
}
