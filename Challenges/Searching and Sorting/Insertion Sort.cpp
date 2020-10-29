#include<iostream>
using namespace std;

int main() {

	int n;
	cin>>n;
	if(n>=1&&n<=1000){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		int temp;
        int j;

		for(int i=1;i<n;i++){
			j=i-1;
			temp=a[i];
			while(j>=0&&a[j]>temp){

            	if(a[j]>temp){
	     		a[j+1]=a[j];
	     		j--;
		   		}
			}
			a[j+1]=temp;
		}

		for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
		}

	}

	return 0;
}
