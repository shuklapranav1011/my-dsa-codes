/*
2 palyers playing.
Can pick a number from either end.

Points = sum of all coins chosen

If player A starts game, maximum margin by which he/she wins.
*/



#include <bits/stdc++.h>
using namespace std;

int dp_f_TD(int *a, int i, int j, int **dp)
{
	if(i>j)
		return 0;

	if(dp[i][j]!=0)
		return dp[i][j];

	int tot_Af = a[i] + min(f(a,i+2,j), f(a,i+1,j-1));
	int tot_Ab = a[j] + min(f(a,i,j-2), f(a,i+1,j-1));

	int tot_A = max(tot_Af, tot_Ab);

	return dp[i][j] = tot_A;
}

void input2DArray(int **a,int m,int n)
{

	for(int i=0;i<m;i++)
		a[i]=new int[n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i][j] = 0;
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

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	int a[n];
	for(auto i=0; i<n; i++) 
		{cin>>a[i];}

int **dp = new int*[n];
input2DArray(dp,n,n);

	cout<<dp_f(a,0,n-1,dp);

	return 0;
}
