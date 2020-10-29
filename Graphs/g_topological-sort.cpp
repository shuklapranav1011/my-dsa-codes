

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


	void topological_sort_dfs_helper(T src, map<T,bool> &visited, deque<T> &q)
	{
		if(visited[src]!=true)
				visited[src]=true;

		for(auto nbr:m[src])
		{
			if(visited[nbr]!=true)
			{
				visited[nbr]=true;
				topological_sort_dfs_helper(nbr,visited,q);
			}
		}

		q.push_front(src);
	}


	void topological_sort_dfs()
	{
		map<T, bool> visited;

		deque <T> q;

		for(auto x:m)
		{
			T node = x.first;
			if(visited[node]!=true)
				topological_sort_dfs_helper(node,visited,q);
		}

		while(!q.empty())
			{
				cout<<q.front()<<endl;
				q.pop_front();
			}
	}
};


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	Graph <string> g;

	g.addEdge("1 Python","2 Data Preprocessing",false);
	g.addEdge("1 Python","3 ML Basics",false);
	g.addEdge("1 Python","4 Pytorch",false);
	g.addEdge("4 Pytorch","5 Deep Learning",false);
	g.addEdge("3 ML Basics","5 Deep Learning",false);
	g.addEdge("5 Deep Learning","7 Face Recog.",false);
	g.addEdge("6 Data Set","7 Face Recog.",false);

	g.topological_sort_dfs();
}



