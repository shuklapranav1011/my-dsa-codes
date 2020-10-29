


#include <bits/stdc++.h>
using namespace std;

int mat_chain_mult(int *a,int n)
{
	int dp[200][200] = {0};
	for(int i=1; i<n; i++)
	{
		int r=0,c=i;

		while(c<n)
		{
			int val = INT_MAX;
			for(int pivot = r; pivot < c; pivot++)
			{
				val = min(val, dp[r][pivot] + dp[pivot+1][c] + a[r]*a[pivot+1]*a[c+1]);
			}
			dp[r][c] = val;
			r++;c++;
		}
	}
return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n; //no. of matrices


/*
dp[i][j] gives us minimum cost to multiply matrices form ith position to jth position.
*/

int a[n];
for(auto i=0; i<n; i++) 
{
	cin>>a[i];
}

cout<<mat_chain_mult(a,n-1);
 
	return 0;
}



