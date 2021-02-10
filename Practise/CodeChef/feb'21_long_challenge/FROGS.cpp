#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

#define mm map<int, int>
#define vv vector<int>
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        mm p_wt; // m[p] = wt
        mm wt_p; // m[wt] = p
        mm wt_l; // m[wt] = l

        vv sortWt(n, 0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            wt_p[x] = i;
            p_wt[i] = x;
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            wt_l[p_wt[i]] = x;
        }

        int i = 0;
        for (auto x : wt_p)
        {
            sortWt[i++] = x.first; //sort kr liya wts
        }

        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int cw = sortWt[i];
            int pw = sortWt[i - 1];

            int cp = wt_p[cw];
            int pp = wt_p[pw];

            //sure pw<cw
            while (cp <= pp)
            {
                cp = cp + wt_l[cw];
                wt_p[cw] = cp;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}