#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main()
{
    IOS long long n = 1000001;
    bool *prime = new bool[n];

    for (int i = 4; i < n; i += 2)
    {
        prime[i] = false;
    }

    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    for (auto i = 3; i < n; i += 2)
    {
        prime[i] = true;
    }

    for (int i = 3; i * i < n; i += 2)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    long long count = 0;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        if (prime[i])
        {
            count++;
        }
        arr[i] = count;
    }

    long long t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long val = arr[x];
        if (y >= val)
        {
            cout << "Chef\n";
        }
        else
        {
            cout << "Divyam\n";
        }
    }
    return 0;
}