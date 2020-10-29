//Total number of setbits between two numbers
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int s=0;
    while(a<=b)
    {
        s=s+__builtin_popcount(a);
        a++;
    }
    cout<<s;
}
