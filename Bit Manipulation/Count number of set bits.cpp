//count set bits
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=0;
    int x=n;
    //M1
    cout<<endl;
    while(x>0)
    {
        if((x&1==1)
            c++;
            x=x>>1;
    }
    cout<<c<<endl;

    //M2
    c=0;
    x=n;
    while(n>0)
    {
        n=n&(n-1);//deletes the last set bit
        c++;
    }
    cout<<c<<endl;

    //m3
    cout<<__builtin_popcount(n);
}
