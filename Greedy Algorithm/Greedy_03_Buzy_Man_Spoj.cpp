/*
Activity Selection Problem

Do as much activities as possible.
Pick activities from a given schedule of activities.
*/


#include <bits/stdc++.h>
using namespace std;

bool compare(pair <int,int> a, pair <int,int> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int maxAct(vector <pair <int,int>> &v)
{
	int ans=0;
	
	sort(v.begin(),v.end(), compare);
	
	pair<int, int> curr_act = v[0];
	ans=1;

	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i].first >= curr_act.second)
		{
			ans++;
			curr_act=v[i];
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;
vector <pair<int,int>> act;
act.reserve(n);
for(int i=0;i<n;i++)
{
	int st,ft;
	cin>>st>>ft;
	act.push_back(make_pair(st,ft));
}

cout<<maxAct(act);

	return 0;
}



