/*
minimum time will be between dish taking most time and sum of times of all dishes
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t; cin>>t;
 	while(t--){
 		int n; cin>>n;
 		if(n==1){
 			int a; cin>>a;
 			cout<<a<<endl;
 		}
 		else if(n==2){
 			int a,b; cin>>a>>b;
 			cout<<max(a,b)<<endl;
 		}
 		else if(n==3){
 			int a,b,c;
 			cin>>a>>b>>c;
 			int maxi = max(a,max(b,c));
 			if(maxi==a)
 				cout<<max(a,b+c)<<endl;
 			else if(maxi==b)
 				cout<<max(b,a+c)<<endl;
 			else if(maxi==c)
 				cout<<max(c,a+b)<<endl;
 		}
 		else if(n==4){
 			int a[4];
 			for(auto i=0;i<4;i++) cin>>a[i];
 			//sorting
 			if(a[0]>a[2])
 				swap(a[0],a[2]);
 			if(a[1]>a[3])
 				swap(a[1],a[3]);
 			if(a[0]>a[1])
 				swap(a[0],a[1]);
 			if(a[1]>a[2])
 				swap(a[1],a[2]);
 			if(a[2]>a[3])
 				swap(a[2],a[3]);
 			//sorting done

 			int t1=0;
 			int t2=0;
 			for(int i=n-1;i>=0;i--){
 				if(t1>t2) t2+=a[i];
 				else t1+=a[i];
 			}
 			cout<<max(t1,t2)<<endl;
 		}
	}
}