/*
Right Angled Triangles
Given N points in a 2D Cartesian Plane, How many right angled Triangles are there such that perpendicualr or base is parallel to x or y axis.
*/


#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

// < cordinate value , < x-co-ordinfate , y-co-ordinate > >

	map <int , int> mx;
	map <int , int> my;
	
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		int x,y;
		cin>>x>>y;

		if(mx.count(x))
		{
			mx[x]++;
		}
		else
		{
			mx[x] = 1;
		}

		if(my.count(y))
		{
			my[y]++;
		}
		else
		{
			my[y] = 1;
		}
	}

int ans=0;
	for(auto x:mx)
	{
		if(my.count(x.first))
		{
			ans+=(x.second - 1)*(my[x.first] - 1);
		}
	}
cout<<ans<<endl;

}
