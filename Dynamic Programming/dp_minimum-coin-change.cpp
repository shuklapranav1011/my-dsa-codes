


#include <bits/stdc++.h>
using namespace std;

int coin[]={1,2,5,10,20,50,100,200,500,2000};

int minCoinExchangeTD(int n,int dp[])
{
	if(n==0)
		return dp[n];
	
	if(dp[n]!=0)
		return dp[n];


	int ans = INT_MAX;
	int subproblem = INT_MAX;

	for(int i=0;i<10;i++)
	{
		if(n-coin[i]>=0)
		subproblem = minCoinExchangeTD(n-coin[i],dp);
		ans = min(ans,subproblem);
	}
	ans = ans+1;

	return dp[n] = ans;
}


int minCoinExchangeBU(int n)
{
	int dp[n+1] = {0};
	int subproblem;
	for(int i=1;i<=n;i++)
	{
		dp[i] = INT_MAX;
		for(int x=0;x<10;x++)
		{
			if(i-coin[x]>=0)	
				 subproblem = dp[i-coin[x]];
			dp[i] = min(dp[i],subproblem+1);
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

int dp[100] = {0};

cout<<minCoinExchangeBU(n);
	return 0;
}




