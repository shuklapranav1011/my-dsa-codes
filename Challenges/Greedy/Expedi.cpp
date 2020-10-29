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

pair<int, int> a[n];

for(auto i=0; i<n; i++) 
{
	int d,f;
	cin>>d>>f;
	a[i]={d,f};
}

int L,F;
cin>>L>>F;

for(auto i=0; i<n; i++) 
	a[i].first = L-d;

priority_queue <int> fuel;

int i=0;
bool flag=true;

while(i<n)
{
	if(F>=a[i].first)
	{
		F-=a[i].first;
		fuel.push(a[i].second);
		i++;
	}
	else
	{
		if(fuel.empty())
		{
			flag = false;
			break;
		}

		F=F+pq.top();
		pq.pop();
	}




}

}
