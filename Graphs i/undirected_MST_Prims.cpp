//UNDIRECTED_GRAPH

/*
In MST we are given a CONNECTED & UN-directed graph.
*/

/*
All computers connected to one-another directly / through intermediate.
Minimize the wire length
*/


/*NOTE WE CANNOT FILL INT_MAX USING memset().  Second Parameter in memset() is a single byte therefore it fills -1 in place of INT_MAX, program may give error.*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

void addEdge(vector<pp> adj[], int u , int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

int find_min_key(int key[], bool MST[], int V){
    int min_Key = INT_MAX;
    int min_ind = -1;
    for(auto v = 0; v<V; v++){
        if(key[v] < min_Key  && MST[v] == false){
            min_Key = key[v];
            min_ind = v;
        }
    }

    return min_ind;
}

int minKey(int key[],bool MST[], int V){

    int min_key = INT_MAX;
    int min_key_index;

    for(auto i = 0; i < V; i++){
        if(MST[i] == false && key[i] < min_key){
            min_key = key[i];
            min_key_index  = i;
        }
    }

    return min_key_index;
}

void prims_MST_adjacency_matrix(vector<vector<int>> graph, int V){
    int parent[V];
    bool MST[V];
    int key[V+1];
    //starting from 0 node
    parent[0] = -1;
    
    for(int i=0; i<V ;i++){
        MST[i] = false;
        key[i] = INT_MAX;
    }
    
    key[0] = 0;

    for(int i = 0; i < V-1; i++){
        int u = minKey(key,MST, V);
        MST[u] = true;

        for(int v = 0; v < V ; v++){
            if(graph[u][v]!=0 &&  MST[v] == false && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout<<"Edge \tWeight\n"; 
    for(auto i = 0;i<V; i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
    }
}

int main(){
    int V = 5;
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };

    cout<<endl;
    
    prims_MST_adjacency_matrix(graph,V);
    cout<<endl;
}