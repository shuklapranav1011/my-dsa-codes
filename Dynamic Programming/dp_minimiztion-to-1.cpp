/*
minimum number of steps required to reduce to  one 
*/


#include <bits/stdc++.h>
using namespace std;

int minimizationTD(int n, int dp[])
{
	if(n==1 || n==2 || n==3 )
		return dp[n];

	if(dp[n]!=0)
		return dp[n];

	int ans;
	if(n%3==0 && n%2==0)
		ans= min(minimizationTD(n%2, dp), min(minimizationTD(n%3, dp), minimizationTD (n-1, dp))) + 1;
	else if(n%2 ==0)
		ans= min(minimizationTD(n%2, dp), minimizationTD (n-1, dp)) + 1;
	else
		ans= minimizationTD (n-1, dp) + 1;

	return dp[n] = ans;
}

int minimizationBU(int n)
{
	int dp[n+1];
	dp[0] = -1;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int ans;
	for(int i=4;i<=n;i++)
	{
		if(i%3==0 && i%2==0)
		dp[i]= min(minimizationTD(n%2, dp), min(minimizationTD(n%3, dp), minimizationTD (n-1, dp))) + 1;
		else if(i%2 ==0)
		dp[i]= min(minimizationTD(n%2, dp), minimizationTD (n-1, dp)) + 1;
		else
		dp[i]= minimizationTD (n-1, dp) + 1;
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
int dp[n+1] = {0};
dp[0] = -1;
dp[1] = 0;
dp[2] = 1;
dp[3] = 1; 

	return 0;
}



