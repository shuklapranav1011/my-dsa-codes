#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(f)
    adj[v].push_back(u);
}

bool isCycle(vector <int> adj[], bool visited[], int src, int parent){

    visited[src] = true;
    for(auto v: adj[src]){
        if(!visited[v]){
            if(isCycle(adj,visited,v,src))
               return true;
        }
        else if(visited[v] == true && v != parent){
            return true;
        }
    }

    return false;
}

bool isCycle_disconnected(vector<int>adj[], int v){
    bool visited[v+1];
    memset(visited, false, sizeof(visited));
    for(int i=0;i<v;i++){
        if(!visited[i])
            if(isCycle(adj,visited,i,-1)){
                return true;
            }
    }
    return false;
}

int main(){
    int v = 6;
	vector<int> adj[v];
	add_Edge(adj,0,1,true);
	add_Edge(adj,1,2,true);
	add_Edge(adj,1,3,true);
	add_Edge(adj,2,3,true);
	add_Edge(adj,2,4,true);
	add_Edge(adj,4,5,true);
	
	cout<<isCycle_disconnected(adj,v)<<endl;
}