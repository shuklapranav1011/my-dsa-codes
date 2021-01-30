//UNDIRECTED_GRAPH

/*
In MST we are given a CONNECTED & UN-directed graph.
*/

/*
All computers connected to one-another directly / through intermediate.
Minimize the wire length
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

void addEdge(vector<pp> adj[], int u , int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void prims_MST(vector<pp> adj[], set<int> &imst, set<int> &nmst, int src, int &wt){

    int temp;
    int temp_weight = INT_MAX;
    for(auto x:adj[src]){
        int v = x.first;
        int w = x.second;
        if(w<temp_weight && nmst.count(v)==0){
            temp_weight = w;
            temp = v;
        }
    }

    imst.insert(temp);
    nmst.erase(temp);

    wt = wt + temp_weight;
    prims_MST(adj,imst,nmst,temp,wt);
}

int prims_MST_init(vector<pp> adj[], int V){
    set<int> imst;
    set<int> nmst;
    for(auto i=0;i<V;i++){
        nmst.insert(i);
    }

    int ele = *nmst.begin();
    imst.insert(ele);
    nmst.erase(ele);
    int wt = 0;
    while(!nmst.empty()){
        int m= *nmst.begin();
        prims_MST(adj,imst,nmst,ele,m);
    }

    return wt;
}


int main(){

    int V = 5;
    vector<pp> adj[V];
    cout<<endl;

    addEdge(adj,0,1,2);
    addEdge(adj,0,3,6);
    addEdge(adj,1,3,8);
    addEdge(adj,1,2,3);
    addEdge(adj,1,4,5);
    addEdge(adj,2,4,7);

    cout<<prims_MST_init(adj,V)<<endl;
    

    int graph1[5][4]={
        {0,5,8,0}, {5,0,10,0}, {8,10,0,20}, {8,10,0,20}, {0,15,20,0}
    };

    int graph2[5][5]={
        {0,2,0,6,0}, {2,0,3,8,5}, {0,3,0,0,7}, {6,8,0,0,9}, {0,5,7,9,0}
    };

    int graph3[5][5]={
        {0,1,0,6,0}, {2,0,3,8,5}, {0,3,0,0,7}, {6,8,0,0,0}, {0,5,7,0,0}
    };

    return 0;
}