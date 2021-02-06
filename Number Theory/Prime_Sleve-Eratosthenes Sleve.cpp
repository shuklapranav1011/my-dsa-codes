#include <bits/stdc++.h>
using namespace std;

vector<int> prime_sieve(int *p, int n)
{
   p[0] = p[1] = 0;
   p[2] = 1;
   for (int i = 3; i <= n; i += 2)
   {
      p[i] = 1;
   }
   for (int i = 3; i <= n; i += 2)
   {
      if (p[i] == 1)
         for (int j = i * i; j <= n; j += i)
            p[j] = 0;
   }

   vector<int> primes;
   primes.push_back(2);
   for (int i = 3; i <= n; i += 2)
      if (p[i] == 1)
         primes.push_back(i);

   return primes;
}

int main()
{
   int *p = new ll[1000001];
   int n;
   cin >> n;
   vector<int> primes = prime_sieve(p, n);
}
