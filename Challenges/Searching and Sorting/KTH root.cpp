#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
    long long n;cin>>n;
    long long k;cin>>k;

    long long beg=0;
    long long last=n;
    long long ans;
    while(beg<=last)
    {
        long long mid=(beg+last)/2;
        if(pow(mid,k)<=n)
        {
            ans=mid;
            beg=mid+1;
        }
        else
            last=mid-1;
    }
    cout<<ans<<endl;
    }
}
