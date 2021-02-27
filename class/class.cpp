#include <bits/stdc++.h>
using namespace std;

class s
{

    int n;

public:
    s()
    {
        n = 0; // default constructor
    }
    s(int x)
    {
        n = x; // paramertized constructor
    }

    s(s &a)
    {
        n = a.n; // copy constructor
    }

    void showData()
    {
        cout << n << "\n";
    }

    ~s() //destructor
    {
        cout << "Me: Omayewa Shinderu  " << n << ": NANI?! "
             << "\n";
    }
};

int main()
{
    s a;
    a.showData();
    s a1(9);
    a1.showData();
}