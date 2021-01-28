/*
When there is a cycle in a directed graph the in-degree of all the vertices cannot become 1;
THerefore the loop terminates with iterations less than the number of vertices.
*/

#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}

bool isCycle(vector<int> adj[], int V){
    vector<int> indeg(V,0);

    //get_indegree
    for(auto i=0;i<V;i++)
        for(auto u: adj[i])
            indeg[u]++;

    //set_queue
    queue<int> q;
    for(auto i=0;i<V;i++)
        if(indeg[i]==0)
            q.push(i);
    
    //check cycle using kahn's
    if(q.empty())
        return true;

    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(--indeg[v] == 0)
                q.push(v);
        }

        cnt++;
    }

    return (cnt!=V);
}

int main(){
    int V = 4;
    vector<int> adj[4];
    add_Edge(adj,0,1);
    add_Edge(adj,1,2);
    add_Edge(adj,0,2);
    add_Edge(adj,2,3);
    cout<<isCycle(adj,V)<<endl;
}