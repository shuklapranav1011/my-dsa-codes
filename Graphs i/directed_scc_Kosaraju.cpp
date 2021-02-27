#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

class Graph
{

    int V;
    vector<int> *graph;
    vector<int> *rev_graph;

public:
    Graph(int n)
    {
        V = n;
        graph = new vector<int>[V];
        rev_graph = new vector<int>[V];
    }

    void add_Edge(int x, int y)
    {
        graph[x].emplace_back(y);
        rev_graph[y].emplace_back(x);
    }

    void dfs(int u, bool visited[])
    {
        visited[u] = true;
        for (auto v : rev_graph[u])
        {
            if (!visited[v])
            {
                cout << v << " ";
                dfs(v, visited);
            }
        }
    }

    void topoRec(int u, bool visited[], stack<int> &s)
    {
        visited[u] = true;
        for (auto v : graph[u])
        {
            if (!visited[v])
                topoRec(v, visited, s);
        }
        s.push(u);
    }

    vector<int> topoSort()
    {
        stack<int> s;
        bool visited[V];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topoRec(i, visited, s);
        }
        vector<int> topo;
        while (!s.empty())
        {
            topo.push_back(s.top());
            s.pop();
        }

        return topo;
    }

    void kosarajuScc()
    {
        vector<int> t = topoSort();
        bool visited[V];
        memset(visited, false, sizeof(visited));

        for (auto u : t)
        {
            if (!visited[u])
            {
                cout << u << " ";
                dfs(u, visited);
                cout << "\n";
            }
        }
    }
};

int main()
{
    IOS

        int V;
    cin >> V;
    Graph g(V);
    while (V--)
    {
        int x, y;
        cin >> x >> y;
        g.add_Edge(x, y);
    }

    g.kosarajuScc();
    return 0;
}