#include<iostream>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    int x;
	    
	    for(auto i=1;i<n;i++)	    	
	    	cin>>a[i];
	    cin>>a[0];
	    
	    for(auto i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
}