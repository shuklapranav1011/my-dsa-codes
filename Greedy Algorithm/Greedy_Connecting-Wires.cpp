/*
There are n white dots and n black dots, equally spaced ina  line.
You want to connect each white dot white some black dots, with a minimum total length of wire.
Find the total minimum length of the wire needed.

inputs:

White Dots Position= []
Black Dots Position= []
*/




#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	int w[n], b[n];
	for(auto i=0; i<n; i++)
	{
		cin>>w[i];
	}
	for(auto i=0; i<n; i++) 
	{
		cin>>b[i];
	}
	sort(w,w+n);
	sort(b,b+n);

int ans = 0;

	for(int i=0;i<n;i++)
	{
		ans+= abs(w[i]-b[i]);
	}
cout<<ans;

}



