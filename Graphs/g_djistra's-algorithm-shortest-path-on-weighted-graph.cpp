
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
	map<T, list< pair<T, int> >> m;

public:
	void addEdge(T x, T y, int d, bool flag)
	{
		m[x].push_back({y,d});
		if(flag)
			m[y].push_back({x,d});
	}

	void djistra_algo(T src)
	{
		//1. make a map to keep distances
		map<T, int> dist;

		//2. set all nodes to infinity
		for(auto x:m)
			dist[x.first] = INT_MAX;

		//3. FIND MINIMIUM DISTANCE OF EACH NODE FROM soruce node

//set to hold minimum distance of a node
//set will be sorted according to the minimum distance

		set<pair<int ,T>> s;
		dist[src] = 0;
		
		s.insert({dist[src],src});

		while(!s.empty())
		{
			auto temp = *(s.begin());
			s.erase(s.begin());  //because distance already found

			T node = temp.second;

			for(auto nbr: m[node])
			{
				auto nbrDist = nbr.second;
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

		//print distances to all other nodes
		for(auto x:m)
		{
			cout<<"distance of "<<x.first<<" with "<<src<<" is "<<dist[x.first]<<endl;

		}
	}
};

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

Graph <int> g;

g.addEdge(1,3,4,true);
g.addEdge(1,2,1,true);
g.addEdge(2,3,1,true);
g.addEdge(3,4,2,true);
g.addEdge(1,4,7,true);
g.djistra_algo(1);

	return 0;
}



