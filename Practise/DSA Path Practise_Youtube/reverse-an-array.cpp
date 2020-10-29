#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}

int start = 0, end = n-1;
	for(auto i=start;i<=end; i++)
	{
		swap(a[start], a[end]);
	}

	for(auto x:a)
		cout<<x<<" ";

}