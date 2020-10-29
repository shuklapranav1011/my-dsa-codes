


#include <bits/stdc++.h>
using namespace std;

void lcs(string s1,string s2)
{

	int m = s1.length();
	int n = s2.length();

	string str = "";
	string dp[m+1][n+1];
	for(int i=0;i<=m;i++)
			dp[i][0]="";

		for(int i=0;i<=n;i++)
			dp[0][i]="";
			
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			string ans = "";
			if(s1[i-1] == s2[j-1])
			{
				ans = dp[i-1][j-1] + s1[i-1];
			}

			else
			{
				string str1,str2;
				str1 = dp[i-1][j];
				str2 = dp[i][j-1];

				if(str1.length() > str2.length())
						ans = str1;
				else
						ans = str2;
			}
			dp[i][j] = ans;
		}
	}
	cout<<dp[m][n];
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

string s1,s2;
cin>>s1>>s2;
lcs(s1,s2);
	return 0;
}



