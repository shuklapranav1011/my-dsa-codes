/*
EXPEDI - Expedition (SPOJ)

Truck leaks one unit of fuel with every kilonetres.

N number of fuel stops where truck can be refilled.
100 units fuel at each stop.

We need to stop at minimum number of stops.

Truck can contain any amount of fuel.

Truck is 25 units away from town.
Distance of fuel stops from town and capacity are given.

Find minimum number of fuel stops to stop at.
*/


/*
Solutions , we will do sorting for stations which we can reach at current capacity.
If I have shortage of fuel, I will pick largest and keep moving.
If I still have shortage I will use second largest.
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair <int,int> a, pair <int,int> b)
{
	return a.first>b.first; //we are given distance from the town not the truck
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n, tx, d, f,D,F,prev=0,x;
	int t;
	cin>>t;

	while(t--)
	{
		vector<pair <int,int>> v;
		priority_queue<int> pq; //to store intermediate fule stations in reverse order of their capacity

		cin>>n;

		for(auto i=0; i<n; i++) 
		{
			cin>>d>>f;
			v.push_back({d,f});
		}

		//Logic

	//1 - Sort cities according to their location from truck
		sort(v,v+n,compare);

		cin>>D>>F;

	//2 - Update distance of fuel stations from the truck

		for(auto i=0; i<n; i++) 
		{
			v[i].first = D- v[i].first;
		}


	//prev denotes previous city we have visited
		prev = 0;
		x = 0;

bool flag = true;

		while(x<n)
		{
			//if we have enough fuel to go to next city
			if(F>=v[x].first - prev)
			{	
				F-= v[x].first - prev;
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else
			{
				//we cannot reach the next city from the current fueling capacity

				//check if have visited some fueling stations in our way

				if(pq.empty())
				{
					flag = false;
					break;
				}

				F+= pq.top();
				//we can only remove fuel station once
				pq.pop();
				ans = ans + 1;
				
				/*Now it may happen that we have reached the a city and we have popped a fuel station 
				but to reach next city we need more fuel and no fuel stations are available further, 
				so we need to keep fill truck from previous station.*/

				continue;
			}

			x++;
		}

		//actually travelled to n fuel stations.
		//what is left you have to reach the town from the last fuel station.

		if(flag == false)
		{
			cout<<"-1"<<endl
			continue;
		}

		//otherwise
		while(F<D)
		{
			if(pq.empty())
			{
				flag = false;
				break;
			}

			F+= pq.top();
			pq.pop();
			ans = ans+1;
		}
		
		if(flag == false)
			{
				cout<<"-1"<<endl;
				continue;
			}

		cout<<ans<<endl;
	}
}


