#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
	adj[u].push_back(v);
	if(f)
	adj[v].push_back(u);
}

void bfs(vector<int> adj[]){
	queue<int> q;
	map<int, bool> m;
	
	q.push(0);
	m[0] = true;
	
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout<<temp<<" ";
		for(auto x:adj[temp]){
			if(m[x]!=true){
				q.push(x);
				m[x] = true;
			}
		}
	}
}

int main(){
	int v=6;
	vector<int> graph[v];
	add_Edge(graph,0,1,true);
	add_Edge(graph,0,2,true);
	add_Edge(graph,0,5,true);
	add_Edge(graph,1,3,true);
	add_Edge(graph,3,5,true);
	add_Edge(graph,2,4,true);
	add_Edge(graph,4,5,true);
	
	bfs(graph);
}
