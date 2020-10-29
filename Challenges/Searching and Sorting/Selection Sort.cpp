#include<iostream>
#include<climits>
using namespace std;

int main() {

	int n;
	cin>>n;
	if(n>=0){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		int curr_index;

		for(int i=0;i<n-1;i++){

            int current=INT_MAX;

			for(int j=i;j<n;j++){
				if(a[j]<current){
					curr_index=j;
					current=a[j];
				}
			}
			swap(a[i],a[curr_index]);
		}

		for(int i=0;i<n;i++){
			cout<<a[i]<<endl;
		}

	}

	return 0;
}
