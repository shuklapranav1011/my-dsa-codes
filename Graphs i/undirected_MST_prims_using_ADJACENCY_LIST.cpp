//NOT COMPLETE

#include <bits/stdc++.h>
using namespace std;

class key_vertex_pair{

    public:
    int vertex;
    int key;
    
    key_vertex_pair(int v, int k){
        vertex = v;
        key = k;
    }
};

class minKey{
    public:
    bool operator()(key_vertex_pair a, key_vertex_pair b){
        return a.key < b.key;
    }
};

void prim_MST_adjacency_list(vector<int> graph[], int V){
    priority_queue <key_vertex_pair, vector<key_vertex_pair>, minKey> p;
    for(int i=1;i<V;i++){
        key_vertex_pair val(i,INT_MAX);
        p.push(val);
    }

    key_vertex_pair val1(0,0);
    p.push(val1);

    for(int cnt = 0; cnt < V-1; cnt++){
        auto x = p.top();
        p.pop();

        int u = x.vertex;
        int k = x.key;

        
    }
}

int main(){

}