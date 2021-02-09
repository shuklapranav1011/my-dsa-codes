#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

#define ll long long
#define lli long long int
#define pp pair<int, int>
#define pp1 pair<pp, pp>

pp get24hr(string s, string ap)
{
    int h1 = (int)s[0] - '0';
    int h2 = (int)s[1] - '0';
    int hh = h1 * 10 + h2;

    if (ap[0] == 'P' && hh != 12)
        hh += 12;

    if (ap[0] == 'A' && hh == 12)
        hh = 0;

    int m1 = (int)s[3] - '0';
    int m2 = (int)s[4] - '0';

    int mm = m1 * 10 + m2;

    return make_pair(hh, mm);
}

int main()
{
    IOS int t;
    cin >> t;

    while (t--)
    {
        string s1;
        string ap1;
        cin >> s1 >> ap1;
        auto t1 = get24hr(s1, ap1);
        int n;
        cin >> n;
        for (int cnt = 1; cnt <= n; cnt++)
        {
            string s2;
            string ap2;
            cin >> s2 >> ap2;
            auto t2 = get24hr(s2, ap2);
            cin >> s2 >> ap2;
            auto t3 = get24hr(s2, ap2);
            if (t1.first >= t2.first && t1.first <= t3.first)
            {
                if (t1.second >= t2.second && t1.second <= t3.second)
                {
                    cout << "1";
                }
                else
                    cout << "0";
            }
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
