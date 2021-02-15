//total numbers between 1 to n which are divisible by any of the prime numbers between 1 to N.

#include <iostream>
using namespace std;
typedef ll long long int main()
{
   ll n;
   cin >> n;
   ll a[] = {2, 3, 5, 7, 11, 13, 17, 19};
   ll denom = 1;
   ll j = 0;
   ll ans = 0;
   for (ll i = 1; i < (1 << 8); i++)
   {
      ll x = i;
      j = 0;
      denom = 1;
      while (x > 0)
      {
         if (x & 1)
            denom *= a[j];
         j++;
         x = x >> 1;
      }
      if (__builtin_popcount(i) & 1)
      {
         ans += (n / denom);
      }
      else
      {
         ans -= (n / denom);
      }
   }
   cout << ans;
   return 0;
}
