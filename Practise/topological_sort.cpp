//directed_Graph
#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

//dfs_topological_sort

void topo_dfs(vector<int> adj[], stack<int> &st, bool visited[], int src){

    visited[src] = true;

    for(auto v: adj[src]){
        if(!visited[v])
            topo_dfs(adj,st,visited,v);
    }

    st.push(src);
}

// void topological_sort(vector<int> adj[], int V){
//     stack<int> st;
//     bool visited[V];
//     memset(visited, false, sizeof(visited));

//     for(auto i = 0; i<V;i++){
//         if(!visited[i])
//             topo_dfs(adj, st, visited, i);
//     }

//     while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }


//bfs_topological_sort ----- Kahn's Algo

void topo_bfs(vector<int> adj[], vector<int> indeg){

    queue<int> q;
    int cnt = 0;
    for(auto i=0;i<indeg.size();i++){
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int src  = q.front();
        q.pop();
        cout<<src<<" ";
        cnt++;
        for(auto v: adj[src]){
            if(--indeg[v] == 0)
                q.push(v);
        }
    }

    cout<<endl;

    if(cnt!=indeg.size())
        cout<<"Cycle Present"<<endl;

}

void topological_sort(vector<int> adj[], int V){
    vector<int> indeg(V,0);
    for(auto i=0;i<V;i++){
        for(auto v:adj[i])
            indeg[v]++;
    }
    
    topo_bfs(adj,indeg);
}

int main(){
    int v = 5;
    vector<int> graphs[v];
    add_Edge(graphs,0,2);
    add_Edge(graphs,0,3);
    add_Edge(graphs,2,3);
    add_Edge(graphs,1,3);
    add_Edge(graphs,1,4);
    // add_Edge(graphs,5,3,false);
    cout<<endl;
    topological_sort(graphs,v);
}