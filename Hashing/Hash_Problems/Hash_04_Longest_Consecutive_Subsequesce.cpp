
#include <bits/stdc++.h>
using namespace std;


void inputset(set <int> &a)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.insert(x);
	}
}

void printset(set <int> &a)
{
	for(auto x: a)
		cout<<x<<" ";
	cout<<endl;
}

int longest_consec_subse(set <int> &arr)
{	
	if(arr.empty())
		return 0;

    int curr_len = 1;
    int ans = 1;
    for(auto x: arr)
    {
        if(arr.find(x-1)!=arr.end())
        {
            curr_len++;
        }
        else
        {
            ans = max(curr_len , ans);
            curr_len=1;
        }
    }

    return max(curr_len, ans);
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

set <int> arr;
inputset(arr);printset(arr);
cout<<longest_consec_subse(arr);
	return 0;
}
