#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    /*
	    int n;
	    cin>>n;
	    int arr[n];
	    for(auto i = 0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+n);
	    int k;
	    cin>>k;
	    cout<<arr[k-1]<<endl;
	    */

		int n;
		cin>>n;
	    priority_queue<int, vector<int>, greater<int>> q;
	    for(auto i = 0;i<n;i++)
	    {
	        int no;
	        cin>>no;
	        q.push(no);
	    }
	    int k;
	    cin>>k;
	    while(k>1)
	    	{q.pop(); k--;}
	    cout<<q.top()<<endl;
	}
}