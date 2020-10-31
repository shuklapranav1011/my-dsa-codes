#include <bits/stdc++.h>
using namespace std;


long long min_jumps(long long arr[], long long n,long long curr_pos, long long dp[]){
	if(curr_pos>=n-1) return dp[curr_pos]=0;
	
	if(arr[curr_pos]==0) return dp[curr_pos]=-1;

	if(dp[curr_pos]!=0)
		return dp[curr_pos];

	long long ans = INT_MAX;
	long long temp;
	long long limit;

	if(curr_pos+arr[curr_pos]>=n-1)		limit=n-1;
	else 								limit=curr_pos+arr[curr_pos];


	for(auto i=curr_pos+1;i<=limit;i++){
		temp = 1+ min_jumps(arr,n,i,dp);
		if(temp==0) continue;
		else        ans = min(temp,ans);  
	}

	if(ans==INT_MAX) ans=-1;

	return dp[curr_pos]=ans;
}



int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
    
    int t; cin>>t;
    while(t--){
    	long long n; cin>>n;
    	long long arr[n];
    	for(auto i=0;i<n;i++) cin>>arr[i];

    	long long dp[n]={0};
    	long long jump = min_jumps(arr,n,0,dp);
    	cout<<jump<<endl;
    }
}
