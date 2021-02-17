//NOT COMPLETE

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;

class Graph
{

    //Adjacency list
    vector<pp> *l; //{node, wt}
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pp>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prims_mst()
    {
        priority_queue<pp, vector<pp>, greater<pp>> q;
        //key,value  (wt, node)
        q.push({0, 0});

        bool mstset[V + 1];
        memset(mstset, false, sizeof(mstset));

        int mstWt = 0;
        while (!q.empty())
        {
            auto temp = q.top();
            q.pop();

            int wt = temp.first;
            int u = temp.second;
            mstWt += wt;
            mstset[u] = true;

            /**/
            for (auto x : l[u])
            {
                int wt = x.second;
                int v = x.first;
                if (!mstset[v])
                    q.push({wt, v}); //remember that queue element is <wt, node>
            }
        }

        return mstWt;
    }
};