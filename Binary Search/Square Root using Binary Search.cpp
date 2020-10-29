//square root of a perfect square using binary search
#include <iostream>
using namespace std;

double sqr(double a)
{return a*a;}

int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        a[i]=i;
int flag=0;int ans;
    int beg=0;int last=n-1;
    while(beg<=last)
    {int mid=(beg+last)/2;
        if(sqr(a[mid])==n)
        {
            cout<<a[mid];
            flag=1;
            break;
        }
        else if(sqr(a[mid])<n)
            {
                beg=mid+1;
                ans=mid;
            }
        else
            last=mid-1;
    }
    if(flag==0)
        cout<<ans;
}
