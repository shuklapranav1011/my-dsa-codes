//for directed graphs

#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[], int u, int v, bool f){
    adj[u].push_back(v);
    if(f)
    adj[v].push_back(u);
}

bool isCycle(vector<int> adj[], bool visited[], bool recStack[], int src){

    visited[src] = true;
    recStack[src] = true;

    for(auto v : adj[src]){
        if(!visited[src]){
            if(isCycle(adj,visited,recStack,v))
                return true;
        }
        else if( recStack[src] == true){
            return true;
        }
    }

    recStack[src] = false; // to remove current from recursion call_stack
    return false;
}


bool isCycle_disconnected(vector<int> adj[], int v){
    bool visited[v+1];
    memset(visited, false, sizeof(visited));

    bool recStack[v];
    memset(recStack,false,sizeof(recStack));

    for(int i = 0; i< v;i++){
        if(!visited[i]){
            if(isCycle(adj,visited,recStack,i))
                return true;
        }
    }

    return false;    
}


int main(){
    int v = 6;
    vector<int> graphs[v];
    add_Edge(graphs,0,1,false);
    add_Edge(graphs,2,1,false);
    add_Edge(graphs,2,3,false);
    add_Edge(graphs,3,4,false);
    add_Edge(graphs,4,5,false);
    add_Edge(graphs,5,2,false);
    add_Edge(graphs,5,3,false);
    cout<< isCycle_disconnected(graphs,v);

}