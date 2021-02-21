#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef pair<int, int> pp;

int main()
{
    IOS

        lli a,
        b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;

    if (c % d == 0)
        cout << ((b - a) / d) - (c / d) + 1;

    else
        cout << ((b - a) / d) - (c / d);

    return 0;
}