//do prime factorization of 60 and with that the powers of (divisior+1)
#include <iostream>
#include <algorithm>
#include <vector>
 using namespace std;

vector<int> primeSieve(int n)
{
          int a[n+1]={0};
          vector <int> primes;
          primes.reserve(n);
          primes.push_back(2);
          for(int i=3;i<=n;i+=2)
                    a[i]=1;
          for(int i=3;i<=n;i+=2)
          {
                    if(a[i]==1)
                    {
                              primes.push_back(i);
                              for(int j=i*i;j<=n;j++)
                                        a[j]=0;
                    }
          }
          return primes;
}

 int divisors(int n)
 {
           vector<int> primes=primeSieve(n);
           int p=primes[0];
           int ans=1;
           int c=0;
           int i=0;
           while(p*p<=n)
           {
                     if(n%p==0)
                              while(n%p==0)
                              {
                                        c++;
                                        n=n/p;
                              }
                    ans*=(c+1);
                    c=0;
                    i++;
                    p=primes[i];
          }
          //no. of divisors
          if(n!=1)
                    ans*=2;
          return ans;
}

 int main()
 {
           int n;
           cin>>n;
           int ans=divisors(n);
           cout<<ans;
 }

