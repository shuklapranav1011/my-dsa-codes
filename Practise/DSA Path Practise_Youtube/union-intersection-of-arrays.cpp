#include <iostream>
#include <set>
using namespace std;

int unionCount(int a[], int b[], int n, int m)
{
    set<int> s;
    for(auto i = 0;i<n;i++)
    s.insert(a[i]);

    for(auto i =0 ;i<m;i++)
    s.insert(b[i]);

    return s.size();
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m]; // a and b are sorted

        for(auto i=0;i<n;i++){
            cin>>a[i];
        }

        for(auto j=0;j<m;j++){
            cin>>b[j];
        }

        cout<<unionCount(a,b,n,m)<<endl;
    }
}