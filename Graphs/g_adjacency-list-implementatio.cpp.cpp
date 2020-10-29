/*

   0---------1
    ----2----
    	1
*/


#include <bits/stdc++.h>
using namespace std;


class Graph
{
	int V;
	list<int> *E;

public:
	Graph(int V)
	{
		this->V = V;
		E = new list<int>[V];
	}

	void addEdge(int x, int y)
	{
		//assuming undirected edge
		E[x].push_back(y);
		E[y].push_back(x);
	}

	void printNeighbour(int x)
	{
		cout<<"Vertex "<<x<<" ---> ";
		for(auto i:E[x])
			cout<<i<<" ";
		cout<<endl;
	}

	void printAllNeighbours()
	{
		for(int i=0; i<V;i++)
			printNeighbour(i);
	}
};

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

int n = 4;

//assuming all edges are undirected
Graph a(4);
a.addEdge(0,1);
a.addEdge(0,2);
a.addEdge(1,2);
a.addEdge(2,3);

a.printAllNeighbours();

	return 0;
}



