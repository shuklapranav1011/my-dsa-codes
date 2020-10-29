#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<string,int>e1,pair<string,int>e2)
{
    if(e1.second==e2.second)
        return e1.first<e2.first;
    return e1.second>e2.second;
}
int main()
{
    int x;cin>>x;
    int n;cin>>n;
    pair<string,int>emp[n];
    for(int i=0;i<n;i++)
    {
        cin>>emp[i].first;
        cin>>emp[i].second;
    }
    sort(emp,emp+n,compare);
    for(int i=0;i<n;i++)
        if(emp[i].second>=x)
            cout<<emp[i].first<<" "<<emp[i].second<<endl;
}
