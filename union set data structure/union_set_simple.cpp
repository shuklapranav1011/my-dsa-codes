#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

#define ll long long
#define lli long long int
#define pp pair<int, int>

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

int main()
{
    IOS
        ll n;
    cin >> n;

    return 0;
}

