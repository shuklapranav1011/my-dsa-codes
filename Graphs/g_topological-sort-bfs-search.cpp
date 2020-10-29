

/*
	0 1
	|/|
	2 4
	|\|
	3-5
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{	
	map<int,int> m;
	int tot_nodes=0;

	void addEdge(int x, int y)
	{
		m[x] = y;
		if(m.count(x)==0)
			tot_nodes++;
		if(m.count(y)==0)
			tot_nodes++;
	}

	void topological_sort()
	{
		int indegree[tot_nodes]={0};

		for(auto x:m)
		{
			for(auto y:x.second)
			{
				indegree[y]++;
			}
		}

		/*assumed that if  nodes, then 0 1 2 3 4 5. for any other use type name */


queue <int> q;

		//bfs
		//1. first find nodes with 0 n degree
		
		for(auto i=0; i<tot_nodes; i++) 
		{
			if(indegree[i]==0)
				q.push(i);
		}

		//start removing elements from the queue
		while(!q.empty())
		{
			int node = q.front();
			q.pop();

			for(auto nbr:m[node])
			{
				indegree[nbr]--;
				if(indegree[nbr]==0)
					q.push(nbr);
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


	return 0;
}



