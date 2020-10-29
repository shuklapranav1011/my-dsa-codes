


#include <bits/stdc++.h>
using namespace std;

//TOP-DOWN
int fiboTD(int n, int dp[])
{
	if(n==0 || n==1)
		return dp[n];

	if(dp[n]!=0)
		return dp[n];

	int ans;
	ans = fib(n-2) + fib(n-1);
	return dp[n] = ans;
}


//Bottom-Up
void fiboBU(int n)
{
	int dp[n]={0};
	dp[1]=1;

//for calculating whole series
	
	/*
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
	*/

// for calcuating just a fibonaci number

//space optimization + bottom up
	int a = 0;
	int b = 1;

	fot(int i=2; i<=n; i++)
	{
		c=a+b;
		a=b;
		b=c;
	}

	return c;

}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	return 0;
}



