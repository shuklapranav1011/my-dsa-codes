#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	long long t;
	cin>>t;
	while(t--){
		long long int x;
		long long int i;
		cin>>x;

		if(x<0)
			cout<<"-1";
		else
		{
			for(i=0; i<=x; i++) {
				long long int a=i&(x-i);
				long long int b=i|(x-i);

				if(a+b==x){
					break;
				}
			}

			cout<<i<<" "<<x-i<<endl;
		}
	}
}
