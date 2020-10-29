/*

common variations;

--> finding minimum/maximum cost path

--> finding number of ways to reach a particular position from a
given starting point in 2D grid and so on.

*/


//find minimum cost
//we can only enter from right or bottom

#include <bits/stdc++.h>
using namespace std;

void print2DArray(int **a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
	}

}

int dp_min_cost(int **a, int n)
{

	int dp[n][n] = {0};

	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i==0 && j==0)
				dp[i][j] = a[0][0];
		else if(i==0)
			dp[i][j] = dp[0][j-1] + a[0][j];
		else if(j==0)
			dp[i][j] = dp[i-1][0] + a[i][0];
		else
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
		}
	}

	return dp[n-1][n-1];
}

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



int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
int n;
cin>>n;

int **a=new int*[n];
input2DArray(a,n,n);
cout<<endl;

print2DArray(a,n,n);
cout<<endl;

cout<<dp_min_cost(a,n);

	return 0;
}
