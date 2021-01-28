/*
Idea: 
Once all the dependents of the parent are recursivly pushed into the stack, we push the parent vertex;

then we have to simply print the stack.

remember : stack is a LIFO : Last In First Out Structure;
remember : stack is not a call by reference structure; 
*/


#include <bits/stdc++.h>
using namespace std;


void add_Edge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void topological_sort(vector <int> adj[], stack<int> &st, bool visited[], int src){

    visited[src] = true;
    for(auto v: adj[src]){
        if(!visited[v])
            topological_sort(adj,st,visited,v);
    }

    st.push(src);
}

void topological_sort_init(vector <int> adj[], int V){
    stack<int> st;
    bool visited[V];
    memset(visited,false, sizeof(visited));
    for(auto i=0;i<V;i++)
        if(!visited[i])
            topological_sort(adj,st,visited,i);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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
    topological_sort_init(graphs,v);
}