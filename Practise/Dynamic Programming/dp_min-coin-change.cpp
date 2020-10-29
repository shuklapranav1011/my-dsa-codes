/*min coin change*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int f_TD(vector <int> coins, int dp[], int n)
{
	if(n==0)
		return dp[n];

	if(dp[n]!=0)
		return dp[n];

	int temp = INT_MAX;
	for(int i=0;i<coins.size();i++)
	{
		if(n-coins[i]>=0)
			temp = min(1+f_TD(coins,dp,n-coins[i]), temp);
	}
	return dp[n] = temp;
}

int f_BU(vector<int> coins, int num)
{
	int dp[num+1] = {0};

	for(int i=1;i<=num;i++)
	{
		int temp = INT_MAX;
		for(int j = 0; j<coins.size(); j++)
		{	
			if(i-coins[j]>=0)
				temp = min(1+dp[i-coins[j]],temp);
		}

		dp[i] = temp;	
	}
	return dp[num];
}


int main()
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};

	int n;
	cin>>n;
	int dp[n+1] = {0};

	cout<<f_BU(coins,n);
}