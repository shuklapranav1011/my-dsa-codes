#include <bits/stdc++.h>
using namespace std;


void add_Edge(vector<int> adj[], int u, int v, bool f){
	adj[u].push_back(v);
	if(f)
	adj[v].push_back(u);
}

void bfs(vector<int> adj[], bool visited[], int src){
	
	queue<int> q;
	q.push(src);
	visited[src] = true;
	
	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();
		
		for(auto v: adj[u]){
			if(visited[v] == false){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void bfs_disconnected(vector<int> adj[], int v){
	bool visited[v+1];
	for(auto i = 0;i < v+1; i++)
		visited[i] = false;
	for(auto i=0;i< v; i++)
		if(visited[i] == false)
			bfs(adj,visited,i);
}

int main(){
	int v = 7;
	vector<int> adj[v];
	add_Edge(adj,0,1,true);
	add_Edge(adj,0,2,true);
	add_Edge(adj,1,3,true);
	add_Edge(adj,2,3,true);
	add_Edge(adj,4,5,true);
	add_Edge(adj,4,6,true);
	add_Edge(adj,5,6,true);
	
	bfs_disconnected(adj,v);
}
