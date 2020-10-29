#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(auto i=0; i<n; i++)
	        cin>>a[i];
	   
	   int x,y,z;
	   x=y=z=0;
	   
	   for(auto i=0;i<n;i++)
	   {
	       if(a[i]==0)
	       x++;
	       if(a[i]==1)
	       y++;
	       if(a[i]==2)
	       z++;
	   }
	   
	   int i=0;
	   while(x--)
	   {
	       a[i++] = 0;
	       cout<<a[i-1]<<" ";
	   }
	   while(y--)
	   {
	       a[i++] = 1;
	       cout<<a[i-1]<<" ";
	   }
	   
	   while(z--)
	   {
	       a[i++] = 2;
	       cout<<a[i-1]<<" ";
	   }
	   
	   cout<<endl;
	}
	return 0;
}

