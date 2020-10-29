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

int count_divisors(int m,vector <int> &primes)
{

      int i=0;
      int ans=1;
      int cnt=0;
      for(int p=primes[i];p*p<=m;i++)
      {
         if(m%p==0)
         {
            cnt=0;
            while(m%p==0)
              {
                 cnt++;
                 m=m/p;
              }
              ans=ans*(cnt+1); //because if 2 to power 3 and 5to power 2 are factors...total divisors are (4*3)
         }
      }
      if(m!=1)
         ans=ans*2;
      return ans;
}
int main()
{
    int p[1000000]={0};
  int n;
  cin>>n;
  vector <int> primes=prime_sieve(p,n);
  int tot_div=count_divisors(n,primes);
  cout<<tot_div;
}
