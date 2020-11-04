#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
//Efficient soln without hashing --- O(1) space complexity
int main(int argc, char const *argv[])
{
    #ifdef ONLINE_JUDGE
    freopen("intput.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x; cin>>x;
        int a[n];
        for(auto i=0;i<n;i++) cin>>a[i];
        int i;
        sort(a,a+n);
        bool flag=false;
        for(i=0;i<n-2;i++){
            int sum=x-a[i];
            int beg=i+1;
            int last=n-1;
        
            while(beg<last){
                int temp = a[beg]+a[last];
         
                if(temp==sum){
                    flag=true; break;
                }
                else if(temp>sum) last--;
                else beg++;
            }
            if(flag) break;
        }
        if(flag) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
*/

//using hashing ---- O(N) space complexity
int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int a[n];
        for(auto i=0;i<n;i++){
            cin>>a[i];
        }

        bool flag=false;
        for(int i=0;i<n-2;i++){
            int sum=x-a[i];
            unordered_set <int> s;
            for(int j=i+1;j<n;j++){
                if(s.find(sum-a[j])!=s.end()){
                    flag=true; break;
                }
                if(flag) break;
                s.insert(a[j]);
            }
        }
        if(flag) cout<<"1"<<endl;
        else     cout<<"0"<<endl;
    }
}