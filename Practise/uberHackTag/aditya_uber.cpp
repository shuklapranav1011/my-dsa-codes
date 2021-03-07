#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> getInterestMap(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{
    map<int, set<int>> friend_interest;
    map<int, bool> visitedWt;                //wt visited
    for (int i = 0; i <= friends_edges; i++) //friends_weights
    {
        friend_interest[friends_weight[i]].insert(friends_from[i]);
        friend_interest[friends_weight[i]].insert(friends_to[i]);
    }
    return friend_interest;
}

int getPowerCouples(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{
    map<int, set<int>> friend_interest = getInterestMap(friends_nodes, friends_edges, friends_from, friends_to, friends_weight);
    map<pair<int, int>, vector<int>> pair_map;

    for (auto x : friend_interest)
    {
        int wt = x.first;
        auto nodes = x.second;
        for (auto itr = nodes.begin(); itr != nodes.end(); itr++)
        {
            int ele = *itr;
            auto itr1 = itr;
            advance(itr1, 1);
            for (; itr1 != nodes.end(); itr1++)
            {
                int ele1 = *itr1;
                pair_map[make_pair(ele, ele1)].push_back(wt);
            }
        }
    }

    int ans = INT_MIN;
    map<int, vector<pair<int, int>>> mapI;
    for (auto x : pair_map)
    {
        mapI[x.second.size()].push_back(x.first);
    }

    auto itr = mapI.rbegin();
    for (auto x : itr->second)
    {
        ans = max(ans, x.first * x.second);
    }
    return ans;
}

int main()
{
    int friends_nodes = 5, friends_edges = 7;

    vector<int> friends_from = {1, 1, 1, 1, 2, 3, 4};
    vector<int> friends_to = {2, 2, 5, 3, 5, 4, 3};
    vector<int> friends_weight = {3, 2, 1, 1, 2, 2, 1};

    int i = getPowerCouples(friends_nodes, friends_edges, friends_from, friends_to, friends_weight);
    cout << i << "\n";
    /// from 1 to friends_nodes

    //any connected vertex a and b by some interest , are said to be in the same interest group

    // two members can be in an interest group even if they are not connected by corressponding edges

    //determine power couple with maximum number of shared interest
}