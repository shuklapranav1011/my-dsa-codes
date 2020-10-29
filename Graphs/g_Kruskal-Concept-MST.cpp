
#include <bits/stdc++.h>
using namespace std;

class DSU
{
	int *parent;
	int *rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for(int i=0;i<n;i++)
		{
			parent[i] = -1;
			rank[i] = -1;
		}
	}

	int find(int i)
	{
		if(parent[i]==-1)
			return i;
		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if(s1!=s2)
		{
			if(rank[s1]<rank[s2])
				{
					parent[s1] = s2;
					rank[s2]+= rank[s1];
				}
			else
				{
					parent[s2] = s1;
					rank[s1]+= rank[s1];
				}
		}
	}
};


class Graph
{
	vector<vector<int>> edgelist;
	int v;

public:
	Graph(int V)
	{
		v=V;
	}

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({w,x,y});
	}

	int kruskal_mst()
	{
		sort(edgelist.begin(),edgelist.end());

		DSU s(v);

		int ans=0;
		for(auto edge: edgelist)
		{
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if(s.find(x)!=s.find(y))
			{
				s.unite(x,y);
				ans+= w;
			}
		}
		return ans;
	}
};


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	Graph g(4);
	g.addEdge(1,1,2);
	g.addEdge(2,1,3);
	g.addEdge(2,1,4);
	g.addEdge(2,2,3);
	g.addEdge(3,2,3);
	g.addEdge(3,3,4);

	cout<<g.kruskal_mst();
}



