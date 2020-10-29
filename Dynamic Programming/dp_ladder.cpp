/*

given, max jump of k on each step.
N step.
No. of ways to reach nth step

*/

#include <bits/stdc++.h>
using namespace std;

int laddersTD(int n,int k,int dp[])
{
	if(n==0)
		{
			dp[n]=1;
			return dp[n];
		}

	if(dp[n]!=0)
		return dp[n];

	int ways = 0;
	for(int i=1; i<=k;i++)
		if(n-i >= 0)
			ways+ = laddersTD(n-i,k,dp);

	return dp[n] = ways;
}
int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	int k;
	cin>>n>>k;

	int *dp = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=0;
	}

	dp[n]=1;

	return 0;
}



