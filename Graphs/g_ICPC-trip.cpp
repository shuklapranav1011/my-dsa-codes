/*
find minimum distance to travel src and destination via train and flight given-

1. Atmost one flight can be taken (optional)

Each edge has prices of train and plane.
*/




#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Graph
{
	map<T, list< pair<T, pair<int,int> >>> m;

public:
	void addEdge(T x, T y, int train, int plane)
	{
		m[x].push_back({y,{train,plane}});
		m[y].push_back({x,{train,plane}});
	}

	map<T, int> djistra_algo(T src)
	{
		//1. make a map to keep distances using train
		map<T, int> dist;

		//2. set all nodes to infinity
		for(auto x:m)
			dist[x.first] = INT_MAX;

		//3. set to store minimum distance from each node using train
		set<pair<int ,T>> s;
		dist[src] = 0;
		
		s.insert({dist[src],src});

		while(!s.empty())
		{
			auto temp = *(s.begin());
			s.erase(s.begin());  //because distance already found

			T node = temp.second; //node at front in set

			for(auto nbr: m[node])
			{
				auto nbrDist = nbr.second.first; //distance from train b/w nbr and node
				auto nbrVal = nbr.first;

				if(nbrDist + dist[node] < dist[nbrVal])
				{
					//remove the old pair and update new pair in set
					auto f = s.find({dist[nbrVal], nbrVal});
					if(f!=s.end())
						s.erase(f);

					dist[nbrVal] = nbrDist + dist[node];
					s.insert({dist[nbrVal], nbrVal});
				}
			}
		}
	}

	int f_Ans(T source, T destination)
	{
		map<T, int> dist1 = djistra_algo(source);
		map<T, int> dist2 = djistra_algo(destination);

//map<T, list< pair<T, pair<int,int> >>> m;

		int ans1 = INT_MAX, ans2 = INT_MAX;
		for(auto x:dist1)
		{	
			auto X = x.first;

			for(auto y:dist2)
			{
				auto Y = y.second;

				if(X==Y)
					continue;

				auto flight_xtoy;
				
				for(auto X:m[X])
				{
					if(X.first == Y)
						flight_xtoy = X.second.second;
				}

				ans2 = min(ans2, dist2[Y] + dist1[X] + flight_xtoy);
			}
			ans1 = min(ans1,ans2);
		}

		return ans1;
	}
};



int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	return 0;
}





