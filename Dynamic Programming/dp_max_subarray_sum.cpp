#include <bits/stdc++.h>
using namespace std;

int dp_maxSum(int a[],int n)
{
	int dp[100] = {0};
	dp[0] = a[0]>0?a[0]:0;
	int maxsum = dp[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = d[i-1] + a[i];
		if(dp[i]<0)
			dp[i] = 0;
		maxsum = max(dp[i],max);
	}

	return maxsum;
}

int dp_maxSum_optimized(int a[],int n)
{
	int maxsum = a[0]>0?a[0]:0;
	int currsum = a[0];

	for(int i=1;i<n;i++)
	{
		currsum+= a[i];
		if(currsum<0)
			currsum = 0;
		 maxsum = max(maxsum,currsum);
	}

	return maxsum;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	return 0;
}
