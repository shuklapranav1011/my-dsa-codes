#include<bits/stdc++.h> 
using namespace std; 
   
void addEdge(vector<int> adj[], int u, int v,bool f) 
{ 
    adj[u].push_back(v);
    if(f) 
		adj[v].push_back(u); 
} 
   
 
void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list for vertex "<< v <<" "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
} 
int main() 
{ 
    int V = 5; 
    vector<int> graph[V]; 
        addEdge(graph, 0, 1,true);
        addEdge(graph, 0, 2,true);
        addEdge(graph, 1, 3,true);
        addEdge(graph, 1, 2,true);
        addEdge(graph, 3, 4,true);
    printGraph(graph, V); 
    return 0; 
} 
