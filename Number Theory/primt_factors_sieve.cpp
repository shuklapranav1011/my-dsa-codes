//first compute all the prime numbers
//this is for times when the value of N is very large;
#include <iostream>
#include <vector>
using namespace std;
vector<int> prime_sieve(int *p,int n)
{
   p[0]=p[1]=0;
   p[2]=1;
   for(int i=3;i<=n;i+=2)
      p[i]=1;
   for(int i=3;i<=n;i+=2)
   {
      if(p[i]==1)
      for(int j=i*i;j<=n;j+=i)
         p[j]=0;
   }
   vector <int> primes;
   primes.push_back(2);
   for(int i=3;i<=n;i+=2)
      if(p[i]==1)
      primes.push_back(p[i]);

   return primes;
}

vector<int> prime_factor_sieve(int m,vector <int> &primes)
{
      vector <int> factors;
      factors.clear();
      int i=0;
      for(int p=primes[i];p*p<=m;i++)
      {
         if(m%p==0)
         {
            factors.push_back(p);
            while(m%p==0)
               m=m/p;
         }
      }
      if(m!=1)
         factors.push_back(m);
      return factors;
}

int main()
{
  int p[1000000]={0};
  int n;
  cin>>n;
  vector <int> primes=prime_sieve(p,n);
  vector <int> factors=prime_factor_sieve(n,primes);
}
