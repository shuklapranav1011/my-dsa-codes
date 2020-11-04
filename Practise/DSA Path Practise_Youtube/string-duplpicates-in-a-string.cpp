


#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	map<char,int> m;
	string s;
	cin>>s;

	for(auto i=0;i<s.length();i++){
		if(m.find(s[i])!=m.end())  m[s[i]]++;
		else  m[s[i]]=1;
	}

	for(auto x: m)
		cout<<x.first<<", "<<"count = "<<x.second<<endl;
	return 0;
}



