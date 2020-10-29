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

	
/*
	if a graph has a backedge, then it can be said to have a cycle.
	a backedge is a path to an already visited node in the current path.
*/

	bool cycle_helper_dfs_directed(T node, map<T,bool> &visited, map<T,bool> &path)
	{
		//visit a node
		visited[node] = true;
		path[node] = true;

		for(T nbr: m[node])
		{
			if(path[nbr] == true)
				return true;
			//else we can check if cycle present form the next node

			if(visited[nbr] != true)
			{
				bool cycle_from_nbr = cycle_helper(nbr, visited, path);
				if(cycle_from_nbr == true)
					return true;
			}
		}

		//leaving a node
		path[node] = false;
		return false;
	}

	bool cycle_detection_in_directed_graph_using_dfs()
	{
		map<T, bool> visited;
		map<T, bool> path;

		T src;
		for(auto x:m)
		{
			src = x.first; 
			break; 
		}

		return cycle_helper_dfs_directed(src,visited,path);
	}


	bool cycle_helper_dfs_undirected(T node, map<T, bool> &visited, T parent)
	{
		visited[node] = true;

		for(auto nbr:m[node])
		{
			/*neighbour not visited thn go visit conecutive neighbour
			and look for cycle in other part of graph*/
			if(visited[nbr]!=true)
			{
			bool isCyclic = cycle_helper_dfs_undirected(nbr, visited, node);
				if(isCyclic)
					return true; 
			}

			//neighbour visited but neighboour not equal to parent
			if(visited[nbr] == true)
			{
				if(parent!= nbr)
					return true;
			}
		}

		return false;
	}

	bool cycle_detection_in_UNdirected_graph_using_dfs()
	{
		/*
		--> in this also we need to find a back edge, but finding a backedge
		is easier in an undirected graph;

		-->if there is more than one way to visit a node.
		-->nbr is not parent node
		*/

		map<T, bool> visited;

		T src;
		for(auto x:m)
		{
			T src = x.first;
			break;
		}

		return cycle_helper_dfs_undirected(src,visited, -1);
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
	g.addEdge(3,4,true);
	g.addEdge(4,0,true);

	if(g.cycle_detection_in_UNdirected_graph_using_dfs())
		cout<<"Contains Cycle";
	else
		cout<<"No cycle Present";

	return 0;
}



