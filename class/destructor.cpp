#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef pair<int, int> pp;

class Sample
{
private:
    int x;

public:
    Sample(int n)
    {
        x = n;
        cout << x
             << "\n";
    }

    ~Sample()
    {
        cout << "\n Destructor Called for pbject value " << x << " ";
    }
};
int main()
{
    IOS
        ll n;

    Sample s1(2);
    Sample s2(3);
    Sample s3(4);

    return 0;
}