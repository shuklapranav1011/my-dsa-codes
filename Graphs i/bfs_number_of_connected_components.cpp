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
		q.pop();
		cout<<u<<" ";
		
		for(auto v: adj[u]){
			if(visited[v] == false){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void bfs_number_of_connected_components(vector<int> adj[], int v){
	
	bool visited[v+1];
	for(auto i=0;i<v+1;i++)  visited[i] = false;
	
	int cnt = 0;
	for(auto i=0;i<v;i++){
		if(visited[i]==false){
			cnt++;
			bfs(adj,visited,i);
		}
	}
	cout<<endl<<"Number of connected components are: "<<  cnt;
}


int main(){
	
	int v = 9;
	vector<int> adj[v];
	add_Edge(adj,0,1,true);
	add_Edge(adj,0,2,true);
	add_Edge(adj,2,1,true);
	add_Edge(adj,3,4,true);
	add_Edge(adj,5,6,true);
	add_Edge(adj,5,7,true);
	add_Edge(adj,7,8,true);
	bfs_number_of_connected_components(adj,v);
	cout<<endl;
}
