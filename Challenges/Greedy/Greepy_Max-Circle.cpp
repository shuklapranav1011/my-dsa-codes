#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b)
{
    if(a.second==b.second) 
        return a.first < b.first;
    return a.second<b.second;
}
int main() {
    int n;
    cin>>n;
    vector< pair<int,int> > v;
    v.reserve(n);
    int c;int r;
    for(int i=0;i<n;++i){
        cin>>c;
        cin>>r;
        v.push_back({c-r,c+r});
    }
    sort(v.begin(),v.end(),comp);
    int curr=v[0].second;
    int ans=1;
    for(int i=1;i<n;++i){
        if(v[i].first>=curr){
            ans++;
            curr=v[i].second;
        }
    }
    cout<<n-ans<<endl;
    return 0;
}