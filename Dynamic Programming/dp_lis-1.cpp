/*
Longest Increasing subsequesnce

LIS -1 <standard>

LIS -2 <tricky>

LIS -3 <2nd + binary search>

LIS -4 <using segment trees>
*/

/*
find the length of the longest subsequence of a given sequence such that
all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} 
is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/


#include <bits/stdc++.h>
using namespace std;

int max_sub_len1(int *a,int n)  //O(n2) --- LIS1 & LIS2
{
	/* dp[i] contains the value of longest subsequence till 
	length i */

	int dp[n];
	dp[0] = 1;
	for(int i=1;i<n;i++)
	{	
		int ans = INT_MIN;
		for(int j=i-1;j>=0;j--)
		{			
			if(a[i]>=a[j])
				ans = max(ans, dp[j]);
		}	

		dp[i] = max(1,1+ans);
	}

	for(int i=0;i<n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return dp[n-1];
}


int max_sub_len3(int *a,int n) // ---- LIS-4
{
	/*	dp[i] value of element at which longest subsequence till i ends.
	*/
	
	int dp[n];
	int point[n];
	
	dp[0] = a[0];
	point[0] = a[0];
	
	for(int i=0;i<n;i++)
	{
		
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
{
	cin>>a[i];
}

cout<<max_sub_len(a,n);

}



