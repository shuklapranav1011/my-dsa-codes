#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

typedef pair<int, int> pp;
class Graph
{

    int V;
    vector<pp> *graph;

public:
    Graph(int n)
    {
        V = n;
        graph = new vector<pp>[V];
    }

    void add_Edge(int x, int y, int w, bool f)
    {
        graph[x].push_back({y, w});
        if (f)
            graph[y].push_back({x, w});
    }

    void djiktraShortestPath()
    {
        bool visited[V];
        memset(visited, false, sizeof(visited));

        priority_queue<pp, vector<pp>, greater<pp>> q;
        // shortestpath, node;

        q.push({0, 0});
        vector<int> shortestPath;
        for (auto i = 0; i < V; i++)
        {
            shortestPath[i] = INT_MAX;
        }

        shortestPath[0] = 0;

        while (!q.empty())
        {
            int wt_u = q.top().first;
            int u = q.top().second;

            visited[u] = true;
            q.pop();

            for (auto x : graph[u])
            {
                int v = x.first;
                int wt_v = x.second;

                if (!visited[v])
                {
                    shortestPath[v] = min(wt_v, shortestPath[u] + wt_u);
                }
            }
        }
    }
};

int main()
{
    IOS

        return 0;
}
