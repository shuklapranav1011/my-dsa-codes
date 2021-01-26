#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(true)
    adj[v].push_back(u);
}

void dfs(vector<int> adj[],bool visited[], int src){
    if(adj[src].empty()){
        return;
    }

    cout<<src<<" ";
    visited[src] = true;

    for(auto x: adj[src]){
        if(!visited[x])
            dfs(adj,visited,x);
    }
}

void dfs_disconnected(vector<int> adj[], int v){
    bool visited[v+1];
    for(int i=0;i< v+1 ;i++){
        visited[i] = false;
    }
    int cnt = 0;

    for(int i = 0; i < v; i++){
        if(visited[i]==false){
            cnt++;
            dfs(adj,visited, i);
        }
    }
    cout<<endl<<"NUmber of components are: "<<cnt<<endl;
}

int main(){
    int v = 7;
    vector<int> graphs[v];
    add_Edge(graphs,0,1,true);
    add_Edge(graphs,0,4,true);
    add_Edge(graphs,2,1,true);
    add_Edge(graphs,3,2,true);
    add_Edge(graphs,5,4,true);
    add_Edge(graphs,4,6,true);
    add_Edge(graphs,5,6,true);
    dfs_disconnected(graphs,v);
}