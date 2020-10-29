
//considering all subarrays and not just consecutive so kadane's  cannot be used


#include <bits/stdc++.h>
using namespace std;


bool checkSum(int arr[], int n)
{

	//store prefix sum in a unordered_map or a unordered_set 
	//we need to only check for 0 value subarrays.
	unordered_set<int> s;

	int pre=0;
	for(auto i=0; i<n; i++)
	{
		pre+=arr[i];
		if(pre==0 || s.find(pre)!=s.end())
			return true;
		s.insert(arr[i]);
	}
	return false;
}

void input1DArray(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<endl;
}

void print1DArray(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

//O(N2) prefix sum array
	int n;
	cin>>n;
	int arr[n];

	input1DArray(arr,n);

	bool f=checkSum(arr,n);
	if(f==true)
		cout<<"Exist"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
