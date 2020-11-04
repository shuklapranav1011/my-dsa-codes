/*New thing learned:- Subsequence and subarray are two very different things. REMEMBER*/

/*


#include<iostream>
#include<climits>
using namespace std;
#define ll long 

int main(int argc, char const *argv[])
{

	int t;
	cin>>t;

	while(t--){
		ll n,q;
		cin>>n>>q;

		ll a[n];
		for(auto i=0;i<n;i++) cin>>a[i];

		while(q--)
		{
			ll x,y; 
			cin>>x>>y;
		
			a[x-1]=y;
			ll len=1;
			ll max_len=INT_MIN;
			for(auto i=0;i<n-1;i++){
				if(a[i]!=a[i+1]){
					len++;
				}
				else{
					max_len=max(max_len,len);
					len=1;
				}
			}

			max_len=max(max_len,len);
			cout<<max_len<<endl;
		}
	}
	return 0;
}


*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

    ll testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll n, q, x, y, count, t;
        cin >> n >> q;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        count = 1, t = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] != a[i + 1])
                count++;
            else
                continue;
            t = max(count, t);
        }
        while (q--)
        {
            cin >> x >> y;
            if (a[x - 1] != y)
            {
                ll t1 = 0;
                if (x - 2 >= 0 && a[x - 2] == a[x - 1])
                    t1++;
                if (x < n && a[x - 1] == a[x])
                    t1++;
                a[x - 1] = y;
                if (x - 2 >= 0 && a[x - 2] == a[x - 1])
                    t1--;
                if (x < n && a[x - 1] == a[x])
                    t1--;
                t += t1;
            }
            cout << t << endl;
        }
    }
}
