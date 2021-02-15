#include <bits/stdc++.h>
typedef IOS
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
using namespace std;

typedef ll long long typedef lli long long int int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        lli *a = new lli[n];
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        lli ans = 2 * (max(abs(a[n - 1] - a[0]), abs(a[n - 2] - a[0])));
        cout << ans << "\n";
    }
    return 0;
}