//graph_is_weighted

//FASTEST_ALGO_____Better_than_djiktras

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

void addEdge(vector<pp> adj[], int u , int v, int w){
    adj[u].push_back(make_pair(v,w));
}

void topo_dfs(vector<pp> adj[],stack<int> &st, bool visited[], int src){
    
    visited[src] = true;
    for(auto x: adj[src]){
        int v = x.first; 
        if(!visited[v])
            topo_dfs(adj,st,visited,v);
    }

    st.push(src);
}

void shortestPath(vector<pp> adj[], int V, int src){

    bool visited[V+1];
    memset(visited, false, sizeof(visited));

    stack <int> st;
    for(auto i=0;i<V;i++){
        if(!visited[i])
            topo_dfs(adj,st,visited,i);
    }

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while(!st.empty()){

        int u = st.top();
        st.pop();
        for(auto x: adj[u]){
            int v = x.first;
            int w = x.second;
            dist[v] = min(dist[v], dist[u] + w); //IMPORTANT
        }
    }

    cout<<endl;
    for(auto x:dist){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int V = 6;
    vector<pp> adj[V];
    addEdge(adj,0,1,2);
    addEdge(adj,1,2,3);
    addEdge(adj,2,3,6);
    addEdge(adj,0,4,1);
    addEdge(adj,4,5,4);
    addEdge(adj,5,3,1);
    addEdge(adj,4,2,2);
    shortestPath(adj,V,0);
}