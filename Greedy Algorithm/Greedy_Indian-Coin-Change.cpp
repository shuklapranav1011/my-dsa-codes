
#include <bits/stdc++.h>
using namespace std;

int make_change(int *coins, int n, int money)
{
	int ans=0;
	 while(money > 0)
	 {
	 	int idx = upper_bound(coins,coins+n,money)-1-coins;
	 	//cout<<coins[idx]<<" + ";
	 	money = money - coins[idx];
	 	ans++;
	 }
	 return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int coins[] = {1,5,10,20,50,100,200,500,2000};
	int len = sizeof(coins)/sizeof(int);
	int n;
	cin>>n;
	cout<<make_change(coins, len, n);
	return 0;
}



