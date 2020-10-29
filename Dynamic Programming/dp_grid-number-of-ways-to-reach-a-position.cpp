


#include <bits/stdc++.h>
using namespace std;


void input2DArray(int **a,int m,int n)
{

	for(int i=0;i<m;i++)
	{
		a[i]=new int[n];
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
}

void print2DArray(int **a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
	}

}

int dp_grid_ways_rat_1(int n) //right and down 1 steps
{
	int dp[n][n] = {0};

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
				dp[i][j] = 1;
			else if(i==0)
				dp[i][j] = dp[i][j-1];
			else if(j==0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}

return dp[n-1][n-1];
}

int fact(int n)
{
	int f=1;
	for(int i=1;i<=n;i++)
		f*=i;
	return f;
}

int dp_grid_ways_rat_2(int m,int n)
{
	//we need to go from 0,0 to m-1,n-1

	int down = m;
	int right = n;

	int ans =  fact(m-1+n-1) / (fact(m-1)*fact(n-1));
	return ans;
}

int dp_grid_ways_elephant_1(int n, int k) // 1 to K steps at a a time
{
	int dp[n][n] = {0};

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int ans = 0;
			
			if(i==0 && j==0)
				dp[i][j] = 1;

			else if(i==0)
			{
				int t=1;
				while(j-t >=0 && t<=k)
				 {ans = ans + dp[i][j-t]; t++;}
			}

			else if(j==0)
			{
				int t=1;
				while(i-t >=0 && t<=k)
				 {ans = ans + dp[i-t][j]; t++;}
			}

			else
			{
				int t=1;
				while(i-t >=0 && t<=k)
				 {ans = ans + dp[i-t][j]; t++;}
				
				t=1;
				while(j-t >=0 && t<=k)
				 {ans = ans + dp[i][j-t]; t++;}
			}

			dp[i][j] = ans;
		}
	}

	return dp[n-1][n-1];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;
int k;
cin>>k;
cout<<dp_grid_ways_elephant_1(n,k);
cout<<endl;


	return 0;
}



