/*
pair chopticks can be made if length diff at most D

find min pairs
*/


#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n,d;
cin>>n>>d;

int a[n];
priority_queue<int, vector<int>, greater<int>> pq;

for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		pq.push(x);
	}

int cc=pq.top();
pq.pop();

int ans=0;
while(!pq.empty())
{
	int temp = pq.top();
	if(temp-cc<=d)
		{
			ans++;
			pq.pop();
			temp = pq.top();
		}
		
	cc = temp;
	pq.pop();
}

cout<<ans;
}