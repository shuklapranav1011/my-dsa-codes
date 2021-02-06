#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{

    ll n = 1000001;
    ll *p = new ll[n];

    for (auto i = 2; i < n; i += 2)
    {
        p[i] = 0;
    }

    p[0] = p[1] = 0;
    p[2] = 1;

    for (auto i = 3; i < n; i += 2)
    {
        p[i] = 1;
    }

    for (auto i = 3; i * i < n; i += 2)
    {
        if (p[i] == 1)
            for (auto j = i * i; j < n; j += i)
                p[j] = 0;
    }

    ll c = 0;
    ll *a = new ll[n];
    for (auto i = 0; i < n; i++)
    {
        if (p[i])
        {
            c++;
        }
        a[i] = c;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (a[x] <= y)
            cout << "Chef" << endl;
        else
            cout << "Divyam" << endl;
    }
    return 0;
}
