//assuming graph is a undirected graph



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

	void dfs_helper(T src, map<T,bool> &visited)
	{
		if(visited[src]!=true)
		{
				cout<<src<<" ";
				visited[src]=true;
		}

		for(auto nbr:m[src])
		{
			if(visited[nbr]!=true)
			{
				cout<<nbr<<" ";
				visited[nbr]=true;
				dfs_helper(nbr,visited);
			}
		}
	}

	void dfs(T src)
	{ 
		map<T,bool> visited;
		dfs_helper(src,visited);
	}

	void find_components()
	{
		map<T,bool> visited;
	int cnt = 0;
		for(auto p:m)
		{
			T node= p.first;
		

			if(visited[node]!=true)
				{
					cout<<"Component "<<cnt<<" ---->";
					dfs_helper(node, visited);
					cout<<endl;
					cnt++;
				}

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

g.addEdge(0,1,true);
g.addEdge(1,2,true);
g.addEdge(2,3,true);
g.addEdge(0,4,true);
g.addEdge(0,3,true);
g.addEdge(5,6,true);
g.addEdge(5,6,true);
g.addEdge(6,7,true);
g.addEdge(8,8,true);

g.find_components();
}



