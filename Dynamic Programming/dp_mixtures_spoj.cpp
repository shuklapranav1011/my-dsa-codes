/*

N mixtures in a row having diff color ranging from 0 to 99.

 To mix all these mixtures.

Mix two consecutive mixtures and put resulting mixture in there place.

mixing two mixure of color a & b:- 
resulting color == (a+b)%100;

smoke generated == a*b

minimum amount of smoke when we mix all the mixtures.
*/


#include <bits/stdc++.h>
using namespace std;

int min_smoke(int *a, int n)
{
	pair<int, int> dp[n][n];
// < smoke, color>

	for(int i=0;i<n;i++)
	{
		int r=0,c=i;

		while(c<n)
		{
			if(r==c)
			{
				dp[r][c].first = 0;
				dp[r][c].second = a[r];
			}

			else
			{

				pair <int,int> val = {INT_MAX, INT_MAX};
				
				for(int pivot = r; pivot < c; pivot++)
				{
					int temp_color = (dp[r][pivot].second + dp[pivot+1][c].second) % 100;
				
					int temp_smoke =  dp[r][pivot].first + dp[pivot+1][c].first + (dp[r][pivot].second * dp[pivot+1][c].second);
				
					pair<int, int> temp = {temp_smoke, temp_color};

					if(val.first>=temp.first)
					{
						val.first = temp.first;
						val.second = temp.second;
					}
				}

				dp[r][c] = val;
			}

			r++,c++;
		}
	}

	return dp[0][n-1].first;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n;
cin>>n;

int mix[n];

for(auto i=0; i<n; i++) cin>>mix[i];

cout<<min_smoke(mix,n);

	return 0;
}



