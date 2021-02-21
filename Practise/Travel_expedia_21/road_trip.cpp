#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    // ll testCases;
    // cin >> testCases;
    // while(testCases--){
    //     ll n ;
    //     cin >> n;
    //     ll c[n];
    //     for(ll i=0;i<n;i++){
    //         cin >> c[i];
    //     }
    //     ll l[n];
    //     for(ll i=0;i<n;i++){
    //         cin >> l[i];
    //     }
    //     ll currentCost = c[0];
    //     ll total = 0 ;
    //     for(ll i=0;i<n;i++){
    //         currentCost = min(currentCost,c[i]);
    //         total = total + currentCost*l[i];
    //     }
    //     cout << total << endl ;
    // }

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x;
        cin >> x;
        ll a[n];
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> v;

        ll currentCost = x;
        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
            if (currentCost > a[i])
            {
                currentCost = a[i];
                v.push_back(i);
            }
        }

        cout << v.size() << "/n";
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "/n";
    }

    return 0;
}