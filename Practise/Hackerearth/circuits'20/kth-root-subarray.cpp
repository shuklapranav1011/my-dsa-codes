

#include <iostream>
#include <cmath>
typedef ll long long using namespace std;

int main(int argc, char const *argv[])
{
#ifdef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, k, q;
	cin >> n >> k >> q;

	int a[n];
	for (auto i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (q--)
	{
		ll flag;
		cin >> flag;

		if (flag == 1)
		{
			ll l, r;
			cin >> l >> r;

			ll beg = l - 1;
			ll last = r - 1;

			ll num = 0;
			ll temp = 1;

			for (auto i = beg; i <= last; i++)
			{
			}

			if (floor(pow(num, 1.0 / k)) == ceil(pow(num, 1.0 / k)))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}

		else if (flag == 2)
		{
			ll l, r;
			cin >> l >> r;

			ll beg = l - 1;
			ll last = r - 1;

			ll x, y;
			cin >> x >> y;

			ll power = pow(x, y);
			for (auto i = beg; i <= last; i++)
				a[i] *= power;
		}

		else if (flag == 3)
		{
			ll l, r;
			cin >> l >> r;

			ll beg = l - 1;
			ll last = r - 1;

			ll x;
			cin >> x;

			for (int i = beg; i <= last; i++)
				a[i] = x;
		}
	}
}
