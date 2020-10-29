//find the number of sub-arrays in an array of length n whose sum is divisible by n;
#include <iostream>
using namespace std;
int main()
{
          int t; cin>>t;
          while(t--)
          {
          int n; cin>>n;
          int a[n];
          int presum[n+1]={0};
          int ans=0;
          int pos[n]={0};
          pos[presum[0]]++;
          for(int i=0;i<n;i++)
          {
                    cin>>a[i];
                    presum[i+1]=(presum[i]+a[i])%n;
                    pos[presum[i+1]]++;
          }
          for(int i=0;i<n;i++)
                    ans+= (pos[i]*(pos[i]-1))/2;
          cout<<ans<<endl;
          }
}

