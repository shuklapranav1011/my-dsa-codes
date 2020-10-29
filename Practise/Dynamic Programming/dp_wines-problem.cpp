/*wines problem*/



#include <bits/stdc++.h>
using namespace std;


int ans(vector<int> wines, int i, int j, int year, int dp[][100])
{
	if(i==j)
		return dp[i][j] = wines[i]*year;

	if(dp[i][j]!=0)
		return dp[i][j];

	int val1 = wines[0]*year + ans(wines,i+1,j,year+1,dp);
	int val2 = wines[1]*year + ans(wines,i,j-1,year+1,dp);

	return dp[i][j] = max(val1,val2);
}

int f(vector<int> wines)
{
	int n=wines.size();
	int dp[100][100] = {0};	

	int year = 1;

	return dp[0][wines.size()-1];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	vector<int> wines = {2,3,5,1,4};
	cout<<f(wines);

	return 0;
}



