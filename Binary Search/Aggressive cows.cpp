#include <iostream>
#include <algorithm>
using namespace std;

bool space_stall(int stalls[],int n,int c,int num)
{
    int currnt_cow=stalls[0];//first cow first stall me
    int cnt=1;

    for(int i=1;i<=n-1;i++)
    {
        if(stalls[i]-currnt_cow>=num){
            currnt_cow=stalls[i];
            cnt++;
            if(cnt==c)
                return true;
        }
    }
    return false;
}
int main()
{
    int n;//stalls
    cin>>n;
    int c;
    cin>>c;//cows;
    int pos[n];//stall positions
    for(int i=0;i<n;i++)
        cin>>pos[i];
    cout<<endl;
    sort(pos,pos+n);

    int sbc[n];//least space between two cows
    for(int i=0;i<n;i++)
        sbc[i]=i;

    int ans;

    int beg=0;int last=n-1;
    while(beg<=last)
    {
        int mid=(beg+last)/2;
        if(space_stall(pos,n,c,sbc[mid])==true)
        {
            ans=sbc[mid];
            beg=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }

    cout<<ans<<endl;
}
