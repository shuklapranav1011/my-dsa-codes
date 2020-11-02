


#include<iostream>
#include<climits>
using namespace std;
#define ll long 

int main(int argc, char const *argv[])
{

	int t;
	cin>>t;

	while(t--){
		ll n,q;
		cin>>n>>q;

		ll a[n];
		for(auto i=0;i<n;i++) cin>>a[i];

		while(q--)
		{
			ll x,y; 
			cin>>x>>y;
		
			a[x-1]=y;
			ll len=1;
			ll max_len=INT_MIN;
			for(auto i=0;i<n-1;i++){
				if(a[i]!=a[i+1]){
					len++;
				}
				else{
					max_len=max(max_len,len);
					len=1;
				}
			}

			max_len=max(max_len,len);
			cout<<max_len<<endl;
		}
	}
	return 0;
}



