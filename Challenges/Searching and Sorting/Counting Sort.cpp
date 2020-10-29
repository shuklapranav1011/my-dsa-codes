#include<iostream>
#include<climits>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int least=INT_MAX;
    int most=INT_MIN;

    for(int i=0;i<n;i++){
        least=min(least,a[i]);
        most=max(most,a[i]);
    }

    int k=most+1;

    int cnt[k]={0};

    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }

    for(int i=1;i<k;i++){
        cnt[i]+=cnt[i-1];
    }

    for(int i=k-1;i>=0;i--){
         cnt[i]=cnt[i-1];
    }
    cnt[0]=0;


    int sorted[n];

    for(int i=0;i<n;i++){
        sorted[ cnt[ a[i] ] ] = a[i];
        cnt[ a[i] ]++;
    }

    for(int i=0;i<n;i++){
        cout<<sorted[i]<<" ";
    }

return 0;
}
