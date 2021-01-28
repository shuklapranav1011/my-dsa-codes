//Directed_graphs

//using bfs

//we need to print zero indegree vertices first
#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(f)
    adj[v].push_back(u);
}

void topological_sort(vector<int> adj[], int v){
    
    vector<int> indeg (v,0);
    //get_indegree
    for(auto i = 0; i< v ;i++){
        for(int u: adj[i])
            indeg[u]++;
    }

    //set_queue
    queue<int> q;
    for(auto i=0;i<v;i++)
        if(indeg[i] == 0)
            q.push(i);
    
    //topological_sort
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<< " ";
        for(auto x: adj[u]){
            if(--indeg[x] == 0)
                q.push(x);
        }
    }
}

int main(){
    int v = 5;
    vector<int> graphs[v];
    add_Edge(graphs,0,2,false);
    add_Edge(graphs,0,3,false);
    add_Edge(graphs,2,3,false);
    add_Edge(graphs,1,3,false);
    add_Edge(graphs,1,4,false);
    // add_Edge(graphs,5,3,false);
    cout<<endl;
    topological_sort(graphs,v);
}