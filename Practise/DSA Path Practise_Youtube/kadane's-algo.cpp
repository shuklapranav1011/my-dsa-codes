#include<iostream>
#include<climits>
using namespace std;
int main(){

	#ifdef ONLINE_JUDGE
	//getting input from the input.txt
	freopen("intput.txt" , "r" , stdin);
	
	//writing output into output.txt
	freopen("output.txt" , "w" , stdout);
	
	#endif
	
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n];
	    for(auto i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    int curr_sum=0, max_sum=INT_MIN;
	    int largest=INT_MIN;
	    for(auto i=0;i<n;i++){
	        curr_sum+=a[i];
	        if(curr_sum<0){
	            curr_sum=0;
	        }
	        largest = max(largest,a[i]);
	        max_sum=max(max_sum, curr_sum);
	    }
	    if(max_sum==0) max_sum=largest;
	    cout<<max_sum<<endl;
	}
}