


#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	int n;
	cin>>n;

	vector <int> r;
	vector <int> c;
r.reserve(n);
c.reserve(n);

	for(auto i=0; i<n; i++) 
	{
		int x,y;
		cin>>x>>y;
		r.push_back(x);
		c.push_back(y);
	}

	sort(r.begin(),r.end());
	sort(c.begin(),c.end());

	int ar = r[0]-0-1;
	int ac = c[0]-0-1;

	for(int i = 1; i<n; i++)
	{
		ar= max(ar, r[i]-r[i-1]-1);
		ac= max(ac, c[i]-c[i-1]-1);
	}

	ar = max(ar, n-r[n-1]);
	ac = max(ac, n-c[n-1]);

	cout<<ar*ac;
}



