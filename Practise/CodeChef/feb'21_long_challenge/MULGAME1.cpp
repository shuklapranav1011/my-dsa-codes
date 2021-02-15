#include <bits/stdc++.h>
typedef IOS
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
using namespace std;

typedef ll long long typedef lli long long int typedef mm map<pair<ll, ll>, ll>

    void solve_same(ll q, lli a[], ll m, ll max_b[], mm &p)
{
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if (a[l] > m)
            continue;

        else if (a[l] <= m && a[r] > m)
        {
            max_b[a[l]]++;
            max_b[m + 1]--;
        }
        else if (a[r] <= m)
        {
            max_b[a[l]]++;
            max_b[m + 1]--;
            p[{a[l], a[r]}]++;
        }
    }
}

void solve(ll m, ll max_b[], mm &p)
{
    for (auto x : p)
    {
        auto i = x.first.first;
        auto j = x.first.second;
        auto k = x.second;
        max_b[i + j] -= k;
        max_b[j + 2 * i] += k;
        auto y = j + 2 * i;
        while (y + j <= m)
        {
            y += j;
            max_b[y] -= k;
            max_b[y + i] += k;
            y += i;
        }
    }
}

int main()
{
    IOS

        int t;
    cin >> t;

    while (t--)
    {
        ll n, q, m;
        cin >> n >> q >> m;
        lli a[n];

        ll max_b[1000001] = {};
        mm *p = new mm();

        for (int i = 0; i < n; i++)
            cin >> a[i];

        solve_same(q, a, m, max_b, *p);
        solve(m, max_b, *p);

        ll maxi = 0;
        for (auto i = 1; i <= m; i++)
        {
            max_b[i] += max_b[i - 1];
        }

        for (auto i = 0; i <= m; i++)
        {
            maxi = max(maxi, max_b[i]);
        }
        cout << maxi << "\n";
    }
}
