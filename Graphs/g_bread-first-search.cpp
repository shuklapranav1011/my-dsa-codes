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
		map<T, bool> m1;

		q.push(src);
		m1[src] = true;

		while(!q.empty())
		{
			T temp = q.front();
			
			q.pop();

			cout<<temp<<" ";

			for(auto temp1: m[temp])
				if(m1[temp1] != true)
					{
						q.push(temp1);
						m1[temp1] = true;
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
g.addEdge(2,1,true);
g.addEdge(0,1,true);
g.addEdge(2,3,true);
g.addEdge(0,3,true);
g.addEdge(3,4,true);
g.addEdge(4,5,true);

g.bfs(0);


	return 0;
}



