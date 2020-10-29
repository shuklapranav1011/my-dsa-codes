/*	jump and jump problem
*/


/*
Minimum number of dice throws required to reach the destination
36 starting from the source. Find shortest path as well.
*/


/*
Assume:
Dice is not random i.e we can fix which number to come.
*/

/*
The graph is non weighted because each node costs 1 through of dice.

----no second chances for 6 on dice.
*/

/*

Observation:

from every node i.
we can have an edge to i+1, i+2,.....,i+6

but if we reach a particular node,
then that node can have either a snake or ladder. 

Thus, 
*/
#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Graph
{
	map <T, list<T>> m;
public:
	void addEdge(T x, T y)
	{
		m[x].push_back(y);
	}

	void bfs(T src, T final)
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

		cout<< dist[final];
	}
};

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	int jump[100] = {0};

	Graph <int> g;

	jump[34] = -22;
	jump[32] = -2;
	jump[24] = -8;
	jump[20] = -14;
	jump[17] = -13;

	jump[2] = 13;
	jump[5] = 2;
	jump[9] = 18;
	jump[18]= 11;
	jump[25]= 10;

	for(int i=1;i<=36;i++)
	{
		int dice = 1;
		while(dice<=6)
		{
			int j = i+dice;
			j+=jump[j];

			if(j<=36)
				g.addEdge(i,j);
			dice++;
		}
	}
	g.addEdge(36,36);
	g.bfs(1,36);
	return 0;
}



