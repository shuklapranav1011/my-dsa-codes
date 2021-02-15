#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef ll long long

	ll
	nCk(ll n, ll k)
{
	ll r = 1;

	if (k > n - k)
		k = n - k;

	for (ll i = 0; i < k; ++i)
	{
		r *= (n - i);
		r /= (i + 1);
	}

	return r;
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		map<ll, ll> m;
		map<ll, ll> m1;
		set<ll> s;
		for (auto i = 0; i < n; i++)
		{
			cin >> a[i];
			m[i] = a[i];
		}

		sort(a, a + n);

		for (auto siz = n; siz >= 3; siz--)
		{
			for (auto i = 1; i <= n; i++)
			{
				ll sum = 0;

				//1st position in set of size=siz
				if (i > 1 && siz - 1 >= i)
				{
					sum += nCk(i, siz - 1);
				}

				//2nd position in set of size=siz
				if (i > 1 && siz - 2 >= i && siz - i - 1 >= 1)
				{
					ll temp1 = nCk(i, siz - 2);
					ll temp2 = nCk(siz - i - 1, 1);
					sum += (temp1 * temp2);
				}

				//3rd position in set of size=siz
				if (i > 1 && siz - 3 >= i && siz - i - 1 >= 2)
				{
					ll temp1 = nCk(i, siz - 3);
					ll temp2 = nCk(siz - i - 1, 2);
					sum += (temp1 * temp2);
				}

				m1[a[i - 1]] = sum;
			}
		}

		//for subset of size=2;
		for (auto i = 1; i < n; i++)
		{
			ll sum = 0;

			sum = n - i - 1 + i;
			m1[a[i - 1]] += sum;
		}

		for (auto i = 0; i < n; i++)
		{
			cout << m1[m[i]] << " ";
		}
	}
}