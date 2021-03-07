#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef pair<int, int> pp;

int kthsmallest(vector<vector<int>> matrix, int k)
{

    int row = matrix.size();
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < row; i++)
    {
        int col = matrix[i].size();
        for (int j = 0; j < col; j++)
        {
            q.push(matrix[i][j]);
        }
    }
    while (k != 1)
    {
        q.pop();
    }
    return q.top();
}

int main()
{
    IOS
        ll n;
    cin >> n;

    return 0;
}
