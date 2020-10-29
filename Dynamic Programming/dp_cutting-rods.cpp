


#include <bits/stdc++.h>
using namespace std;

void inputArray1D(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void print1DArray(int *a,int n)
{
	a[0] = 0;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}

int maxSP_TD(int *a,int n, int dp[])
{
	if(n==0)
		return dp[n];

	if(dp[n]!=0)
		return dp[n];

	int ans = INT_MIN;

	for(int i=0;i<=n;i++)
	{
		int temp1;
		int temp2;

		temp1 = cost[i];
		temp2 = maxSP_TD(a,n-i,dp);

		ans = max((temp1+temp2),ans);
	}

	return dp[n] = ans;
}

int maxSP_BU(int *c,int n)
{
	int dp[n+1] = INT_MIN;
	dp[0] = c[0];
	for(int j=1; j<=n; j++)
	{
		for(int i=0;i<=j;i++)
		{
			int temp1;
			int temp2;

			temp1 = cost[i];
			temp2 = dp[j-i];

			dp[i] = max(temp1+temp2, dp[i]);
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;
int cost[n+1];
int dp[n+1] = 0;

dp[0] = 0;

inputArray1D(cost,n+1);

int max_profit(a,n,dp);
return max_profit;

	return 0;
}



