//print all prime numbers till n with minimum complexity
#include <iostream>
using namespace std;

void prime_sieve(int *a,int n)
{
   //1 means  prime
   //0 means not prime
   long long i,j;
   //first marking all odd as prime
   for(i=3;i<=n;i+=2)
      a[i]=1;

   for(i=3;i<=n;i+=2)
   {
      if(a[i]==1)
         for( j=i*i;j<=n;j=j+i)
            a[j]=0;
   }
   a[0]=a[1]=0;
   a[2]=1;
}

int main()
{
   long long n;
   cin>>n;

   //making a sieve of all primes
   int p[n+1]={0};
   prime_sieve(p,n);

   //printing primes till n
   for(long long i=0;i<=n;i++)
   {
      if(p[i]==1)
         cout<<i<<" ";
   }

}
