#include <bits/stdc++.h>
using namespace std;

bool isMatch(string str, int i, string pat, int j, unordered_map<char, string> &map)
{
    int n = str.size(), m = pat.size();
    if (n < m)
    {
        return false;
    }
    if (i == n && j == m)
    {
        return true;
    }
    if (i == n || j == m)
    {
        return false;
    }
    char curr = pat[j];
    if (map.find(curr) != map.end())
    {
        string s = map[curr];
        int k = s.size();
        if (str.substr(i, k).compare(s))
        {
            return false;
        }
        return isMatch(str, i + k, pat, j + 1, map);
    }

    for (int k = 1; k <= n - i; k++)
    {
        map[curr] = str.substr(i, k);
        if (isMatch(str, i + k, pat, j + 1, map))
        {
            return true;
        }
        map.erase(curr);
    }
    return false;
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    unordered_map<char, string> map;
    if (isMatch(str, 0, pat, 0, map))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}