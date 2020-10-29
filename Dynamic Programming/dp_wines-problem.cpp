


#include <bits/stdc++.h>
using namespace std;

int winesTD(int i,int j,int y,int *p,int **dp)
{
	if(i==j)
	{
		dp[i][j] = p[i]*y;
		return dp[i][j];
	}

	if(dp[i][j]!=0)
		return dp[i][j];

	//Rec
	int sell_first = p[i]*y + winesTD(i+1,j,y+1,p,dp);
	
	int sell_last = p[j]*y + winesTD(i,j-1,y+1,p,dp);

	dp[i][j] = max(sell_last,sell_first);
	return dp[i][j];
}

int winesBU(int n,int *p, int **dp)
{

int i,j;
int k=0;

int y=5; //because inner most layer comes when we have already sold upper
	while(k<n)
	{
		for(i=0,j=k; i<n-k,j<n ;i++,j++)
		{
			if(i==j)
				dp[i][j] = p[i]*y;

			else
			{
				int sell_first = p[i]*y + dp[i+1][j];
				int sell_last = p[j]*y + dp[i][j-1];
				dp[i][j]= max(sell_last,sell_first);
			}
		}
		k++;
		y--;
	}
	
	
	for(auto i=0; i<n; i++) 
	{
		for(auto j=0; j<n; j++) 
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
	}
	cout<<endl;

	return dp[0][n-1];
}


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++)
		cin>>p[i];

	int **dp= new int*[n];
	for(auto i=0; i<n; i++) 
	{
		dp[i] = new int [n];
		for(auto j=0; j<n; j++) 
			{
				dp[i][j] = 0;
			}
	}

	int profit = winesBU(n,p,dp);
	cout<<profit;
}



