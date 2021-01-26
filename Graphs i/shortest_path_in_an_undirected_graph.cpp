/*shortest distance from souce to everyother vertex*/

/*bfs in itself uses shortest path algorithm to reach each element from a given node*/

#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(true)
    adj[v].push_back(u);
}

void shortest_path_initializer(vector<int>adj[], int v, int src){
    int dist[v];
    memset(adj,0,sizeof(adj));
    bool visited[v+1];
    memset(visited,false, sizeof(visited));
    queue<int> q;
    q.push(src);
    visited[src] = true;  

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!visited[v]){
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main(){
    
}