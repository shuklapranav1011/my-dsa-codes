/*
tho string given find longest common subsequence.
*/





#include <bits/stdc++.h>
using namespace std;

int lcs_dp(char *x, char*y, int i,int j,int **dp)
{
	int m = strlen(x);
	int n = strlen(y);

	int dp[100][100];

	for(auto i=0; i<m; i++) dp[i][0] = 0;
	for(auto i=0; i<n; i++) dp[0][i] = 0;

	for(auto i=0; i<m; i++) 
	{
		for(auto j=0; j<n; j++) 
		{
			int q=0;
			if(x[i-1] == y[j-1])
				q= 1+ dp[i-1][j-1];
			else
				q= max(dp[i-1][j], dp[i][j-1]);
		}
		dp[i][j] = q;
	}
	return dp[m][n];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

string x,y;
cin>>x>>y;

cout<<lcs_TD(x,y,0,0,dp);

	return 0;
}



