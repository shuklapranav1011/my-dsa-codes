#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int v;
	cin>>v;

	int key[v];
	bool visited[v];
	fill(visited, visited+v, false);
	fill(key, key+v, INT_MAX);
	key[0] = 0;


	return 0;
}



