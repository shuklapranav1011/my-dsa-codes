#include <iostream>
using namespace std;
typedef ll long long int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll x, y;
		cin >> x >> y;

		if (x < y)
		{
			ll t = y - x;
			if (!(t & 1))
				cout << "2";
			else
				cout << "1";
		}
		else if (x > y)
		{
			ll t = x - y;
			if (!(t & 1))
				cout << "1";
			else
				cout << "2";
		}
		else
			cout << "0";
		cout << endl;
	}
}