//check if a string is a subsequence of another string

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1, s2;
	cin>> s1>> s2;
	int pos = -1;
	int flag = 1;
	for(int i=0;i< s2.length(); i++){
		char x = s2[i];
		
		int p = s1.find(x, pos+1);
		if(p == -1){
			flag = 0;
			break;
		}else{
			pos = p;
			continue;
		}
	}

	if(flag)
		cout<< true;
	else
		cout<< false;
}