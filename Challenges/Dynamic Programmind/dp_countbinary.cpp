


#include <iostream>
using namespace std;

int countbinary(int n)
{
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 2;

	for(int i=2;i<=n;i++)
	{
		int temp1 =0, temp2 = 0;
		if(i-1>=0)
			 temp1 = dp[i-1];
		if(i-2>=0)
			 temp2 = dp[i-2];

		dp[i] = temp1 + temp2;
	}

	return dp[n];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<countbinary(n)<<endl;
	}
}



