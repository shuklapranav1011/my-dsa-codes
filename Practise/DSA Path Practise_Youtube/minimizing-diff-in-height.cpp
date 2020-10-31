


#include <bits/stdc++.h>
using namespace std;


void inputArray1D(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void print1DArray(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
 
int getMinDiff(int arr[], int n, int k) {
       sort(arr, arr+n);
       int ans = arr[n-1]-arr[0];
       
       int small = arr[0]+k;
       int big = arr[n-1]-k;
    
       if(small>big) swap(small, big);
    
       for(auto i=1;i<n-1;i++){
       		int subtract = arr[i]-k;
       		int add= arr[i]+k;
    
       		if(subtract>=small || add<=big) continue;   
       		/*if subtration is within our max/min limits then subtraction is done. 
       							or
       		 if addition is within our max/min limits then addition is.
			
			 if both are within our limits then either can be done.

			 But if both subtraction and addition exceed current limits, then we need to change the limts.
			 Hence, we need to decide if subtraction needs to be done or additoin.
       		 */
    
       		if(big-subtract <= add-small)  small = subtract;
       		else 						   big = add;
       }
    
       return min(ans,big-small);   
    }

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
int k; int n;
cin>>k>>n;
int arr[n];
inputArray1D(arr,n);

cout<<getMinDiff(arr,n,k);
	return 0;
}



