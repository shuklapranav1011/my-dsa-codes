#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<endl;
    int s=0;
    int c=1;
    while(n>0)
    {
        s=s+((n&1)*c);
        c=c*10;
        n=n>>1;
    }
    cout<<s<<endl;
}
