/*
Kingdom Defence SPOJ

find the largest indefended rectangle
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int m,n,k;
cin>>m>>n>>k;
vector <pair<int, int>> t;

int x[k];
int y[k];
for(int i=0;i<n;i++)
{
	cin>>x[i];
	cin>>y[i];
}

sort(x,x+k);
sort(y,y+k);

int ansx = x[0] - 1 ;
int ansy = y[0] - 1 ;

for(int i=1;i<k;i++)
{
	ansx = max(x[i]-x[i-1] -1,ansx);
	ansy = max(y[i]-y[i-1] -1,ansy);
}

ansx = max(m-x[k-1],ansx);
ansy = max(n-y[k-1],ansy);

cout<<ansx*ansy;

	return 0;
}
