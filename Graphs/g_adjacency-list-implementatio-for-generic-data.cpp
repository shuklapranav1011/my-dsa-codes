
/*
		  20
		A----B
		|\ 20| 
		| \  |
	  10|  \ |30
		|   \|
		C----D
		  40
*/

/*
Here we cannot use list.
So we use hashmaps.
They are suited for generic data.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	unordered_map< string, list< pair< int,string>>> m;

public:
	void addEdge(string x, string y, int w, int flag)
	{
		m[x].push_back({w,y});

		if(flag==true)
			m[y].push_back({w,x});
	}

	void printNeighbour(list<pair<int,string>> l)
	{
		cout<<" ";
		for(auto i:l)
			cout<<i.first<<" , "<<i.second<<"  ";
	}

	void printAllEdges()
	{
		for(auto x:m)
		{
			cout<<"Vertex is "<<x.first<<"-->";
			printNeighbour(x.second);
			cout<<endl;
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
