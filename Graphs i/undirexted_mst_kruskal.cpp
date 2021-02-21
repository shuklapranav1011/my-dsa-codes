#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef pair<int, int> pp;

class disjointSet
{

    int n;
    int *parent;
    int *rank; // for union by rank

public:
    void init(int len)
    {
        n = len;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;
        return find(parent[x]);
    }

    void union_(int x, int y)
    {
        int x_r = find(x);
        int y_r = find(y);

        if (x_r == y_r)
            return;
        parent[y_r] = x_r;
    }

    int find_pc(int x)
    {
        if (x == parent[x])
            return;
        parent[x] = find(parent[x]);

        return parent[x];
    }

    void unionbyRank(int x, int y)
    {

        int x_rep = find(x);
        int y_rep = find(y);
        int rankX = rank[x];
        int rankY = rank[y];

        if (x_rep == y_rep)
            return;

        if (rankX > rankY)
            parent[y_rep] = x_rep;
        else if (rankY > rankX)
            parent[x_rep] = y_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

class edge
{

public:
    int src, dest, wt;

    edge()
    {
        src = 0, dest = 0, wt = 0;
    }

    edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

class Graph
{

    int V;
    vector<edge> g;

public:
    Graph(int len)
    {
        V = len;
    }

    void addEdge(int s, int d, int w)
    {
        g.push_back(edge(s, d, w));
        /*the graph is undirected but we only want the edge list*/
    }

    bool cmp(edge e1, edge e2)
    {
        return e1.wt < e2.wt;
    }

    int mstkruskal()
    {
        //vector<edge> outputmst(g.size());

        sort(g.begin(), g.end(), cmp);

        disjointSet dsu;
        dsu.init(V);

        int mstWt = 0;

        for (int i = 0, s = 0; s < V - 1; i++)
        {
            edge e = g[i];
            int x = dsu.find(e.src);
            int y = dsu.find(e.dest);

            if (x != y)
            {
                dsu.union_(e.src, e.dest);
                mstWt += e.wt;
                //outputmst[s] = e;
                s++;
            }
        }

        return mstWt;
    }
};

int main()
{
    IOS
        ll n;
    cin >> n;

    return 0;
}
