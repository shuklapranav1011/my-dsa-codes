//Directed_graphs
#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(true)
    adj[v].push_back(u);
}

void topological_sort(vector<int> adj[],bool visited[], int src){

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        for(auto v: adj[temp]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void topological_sort_disconnected(vector<int> adj[], int v){
    bool visited[v + 1];
    memset(visited, false, sizeof(visited));

    for(auto i=0;i<v;i++){
        if(!visited[i])
            topological_sort(adj,visited,i);cout<<endl;
    }
}

int main(){
    int v = 6;
    vector<int> graphs[v];
    add_Edge(graphs,0,1,false);
    add_Edge(graphs,2,0,false);
    add_Edge(graphs,3,1,false);
    add_Edge(graphs,3,2,false);
    add_Edge(graphs,4,3,false);
    add_Edge(graphs,5,3,false);
    topological_sort_disconnected(graphs,v);
}