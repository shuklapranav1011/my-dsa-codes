#include <iostream>
#include <set>
using namespace std;

#define ll long long

int main()
{
int t;
cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	set <ll> a;
    	for(ll i=1;i<n+1;i++)
        	{
                int x;
                cin>>x;
    	    	a.insert(x);
        	}
        cout<<a.size()<<endl;;
    	
	}
}

