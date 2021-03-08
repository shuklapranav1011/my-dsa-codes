#include <bits/stdc++.h>
using namespace std;

int f_BU(vector<int> coins, int num)
{
	int dp[num + 1];
	for (int i = 0; i <= num; i++)
	{
		dp[i] = 0;
	}

	for (int i = 1; i <= num; i++)
	{
		int temp = INT_MAX;
		for (int j = 0; j < coins.size(); j++)
		{
			if (i - coins[j] >= 0)
				temp = min(1 + dp[i - coins[j]], temp);
		}

		dp[i] = temp;
	}
	return dp[num];
}

int main()
{
#ifdef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> coins;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		coins.emplace_back(x);
	}

	int V;
	cin >> V;
	int dp[V + 1];
	for (int i = 0; i <= V; i++)
	{
		dp[i] = 0;
	}
	cout << f_BU(coins, V) << "\n";
}