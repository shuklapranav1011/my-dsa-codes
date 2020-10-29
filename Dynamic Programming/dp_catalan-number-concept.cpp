/*
Count bsts that can be formed using n number of nodes numbered
from 1 to n.
*/

#include <bits/stdc++.h>
using namespace std;

int f(int n) //number of bst
{
	int dp[100] = {1};

	dp[0] = 1; //NULL TREE
	dp[1] = 1;

	for(int i=2; i<=n; i++)
	{
		int ans = 0;
		for(int j=1; j<=i; j++)
			ans+= dp[j-1] * dp[i-j];

		dp[i] = ans;
	}
	return dp[n];
}

int f1(int n) // number of binary trees
{
	//factorial(n) * f(n);
}

int f2(int n) //number of unlabelled binary tree
{
	f(n);
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;

cout<<f(n);
	return 0;
}



