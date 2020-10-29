//SPOJ - Biased Standing

#include <bits/stdc++.h>
using namespace std;

bool compare(pair <string , int> a,pair <string , int> b)
{
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;

vector < pair <string , int> > rl;
rl.reserve(n);

for(auto i=0; i<n; i++)
{
	string s; int r;
	cin>>s>>r;
	rl.push_back(make_pair(s,r));
}

sort(rl.begin(),rl.end(),compare);

int ans=0;
for(auto i=0; i<n; i++) 
{
	ans += abs( (i+1) - rl[i].second );
}

cout<<ans;

	return 0;
}



