
#include <bits/stdc++.h>
using namespace std;

void inputArray1D(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void print1DArray(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}

int length_of_longest_subarray_with_sum_k(int *a,int n,int k)
{
	int pre = 0;

	int len = 0;
	unordered_map<int,int> m;
	
	for(int i=0;i<n;i++)
	{
		pre+=a[i];
		
		if(pre == k)
		{
			len = max(len,i+1);
		}

		if(m.count(pre - k))
		{
			len = max(len , i - m[pre - k]);
		}
		else
		{
			m[pre] = i;
		}
	}
	return len;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	int arr[n];

	inputArray1D(arr,n);

	int csum;
	cin>>csum;

	cout<<length_of_longest_subarray_with_sum_k(arr, n ,csum);
	return 0;
}
