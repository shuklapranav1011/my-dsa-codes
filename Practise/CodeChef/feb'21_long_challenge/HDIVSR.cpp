#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int t = 11;
    while (--t)
    {
        if (n % t == 0)
        {
            cout << t << endl;
            break;
        }
    }
    return 0;
}