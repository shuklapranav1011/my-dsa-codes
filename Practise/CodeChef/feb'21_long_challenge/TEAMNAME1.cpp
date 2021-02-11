#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

#define ll long long
#define lli long long int

#define mm map<string, ll>
#define mm1 map<ll, set<char>>

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

int main()
{
    IOS

        int t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;

        mm s_cnt_no; //map[string] = container number
        ll cnt_no = 0;
        ll dist_no = 0;
        set<char> dist;
        mm1 dist_same_cont_no;

        for (auto i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            char ch = s[0];
            s.erase(s.begin() + 0);
            if (s_cnt_no.count(s) != 1)
                s_cnt_no[s] = ++cnt_no;

            dist.insert(ch);
            dist_same_cont_no[s_cnt_no[s]].insert(ch);
        }

        dist_no = dist.size();

        ll ans;
        ans = fastComb(dist_no, 2);
        ll temp = 0;
        for (auto x : dist_same_cont_no)
            temp += fastComb(x.second.size(), 2);

        ans = ans - temp;
        // ans *= fastComb(cnt_no, 2);
        ans *= 2;

        cout << ans << "\n";
    }

    return 0;
}