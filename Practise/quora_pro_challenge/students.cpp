#include <bits/stdc++.h>
using namespace std;

typedef ll long long int main()
{
    ll m, n;
    cin >> n >> m;
    ll **a = new ll *[m];
    for (int i = 0; i < m; i++)
        a[i] = new ll[4];

    vector<ll> graph[n * n];

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }

    for (auto i = 0; i < m; i++)
    {
        auto x1 = (a[i][0] - 1) * n;
        auto y1 = (a[i][1] - 1);
        auto x2 = (a[i][2] - 1) * n;
        auto y2 = (a[i][3] - 1);
        // cout << x1 + y1 << " " << x2 + y2 << endl;
        graph[x1 + y1].push_back(x2 + y2);
        graph[x2 + y2].push_back(x1 + y1);
    }

    for (auto i = 0; i < n * n; i++)
    {
        for (auto x : graph[i])
            cout << x << " ";
        cout << endl;
    }
}