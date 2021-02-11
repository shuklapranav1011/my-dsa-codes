#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

#define ll long long
#define lli long long int

#define mm map<string, set<char>>

ll fastComb(ll n, ll r)
{
    if (n < r)
        return 0;

    int ans = 1;

    if (r > n - r)
        r = n - r;
    for (int i = 0; i < r; ++i)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }

    return ans;
}

ll sameContainers(set<char> s1, set<char> s2)
{
    ll same = 0;
    for (auto x : s1)
        if (s2.count(x) == 1)
            same++;
    return same;
}

int main()
{
    IOS

        int t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;
        mm s_ch;

        for (auto i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            char ch = s[0];
            s.erase(s.begin() + 0);
            s_ch[s].insert(ch);
        }

        ll ans = 0;

        for (auto x = s_ch.begin(); x != s_ch.end(); x++)
        {
            for (auto y = x; y != s_ch.end(); y++)
            {
                ll same = 0;
                if (x->first != y->first)
                {
                    same = sameContainers(x->second, y->second);
                    ans += 2 * (x->second.size() - same) * (y->second.size() - same);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}