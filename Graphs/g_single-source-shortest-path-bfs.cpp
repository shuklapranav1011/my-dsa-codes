/*

BFS

2 ---------- 1
|            |
|            |
|            |
|            |
3 ---------- 0
|
|
|
4 ---------- 5

*/

/*

Distance calculated by a level order traversal is the shortest
given that graph is not weighted.
*/


/*
shortest path to source to destination.
*/


#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Graph
{
	map <T, list<T>> m;
public:
	void addEdge(T x, T y, bool flag)
	{
		m[x].push_back(y);

		if(flag)
			m[y].push_back(x);
	}

	void bfs(T src)
	{
		queue<T> q;
		map<T, int> dist;

		//all other nodes will have infinte distance
		for(auto x:m)
		{
			T key = x.first;
			dist[key] = INT_MAX;
		}


		q.push(src);
		dist[src] = 0;

		while(!q.empty())
		{
			T node = q.front();
			
			q.pop();

			for(auto nbr: m[node])
				{
					if(dist[nbr] == INT_MAX)
					{
						q.push(nbr);
						dist[nbr]= dist[node] + 1;
					}
				}
		}

		for(auto x:m)
		{
			T node = x.first;
			int d = dist[node];
			cout<<" Node " << node <<" Dist from Node "<<src<<" is "<<d<<endl;
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
g.addEdge(2,1,true);
g.addEdge(0,1,true);
g.addEdge(2,3,true);
g.addEdge(0,3,true);
g.addEdge(3,4,true);
g.addEdge(4,5,true);

g.bfs(0);


	return 0;
}



