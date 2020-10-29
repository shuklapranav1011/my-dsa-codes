/*
initially one cell.
want n.

can double. cost x.
can +1. cost y.
can -1. cost z.
*/


#include <bits/stdc++.h>
using namespace std;

int cell_mitosis_BU(int n, int x, int y, int z)
{
	int dp[100];
	dp[0] = dp[1] = 0;

	for(int i=2; i<n; i++)
	{
		if(i&1==1)
		{
			//no i/2 part
			int temp1 = dp[i-1] + y;
			int temp2 = dp[(i+1)/2] + x + z;
			dp[i] = min(temp1,temp2);
		}
		else
		{
			//	i/2 part present
			int temp1 = dp[i-1] + y;
			int temp2 = dp[i/2] + x;
			dp[i] = min(temp1,temp2);
		}
	}
	int ans = dp[n-1];
	return ans;
}
int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n,x,y,z;
cin>>n>>x>>y>>z;

int dp[100];
dp[0] = 0;
dp[1] = 0; // because 1 cell is already given

cout<<cell_mitosis_BU(n,x,y,z);

}



