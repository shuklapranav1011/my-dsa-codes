
#include <bits/stdc++.h>
using namespace std;


void print(vector<string> &v)
{
	for(auto x:v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	unordered_map<string,vector <string>> phonebook;

	phonebook["Papa"].push_back("9450150555");
	phonebook["Papa"].push_back("6306458298");
	phonebook["Mummy"].push_back("9453811449");
	phonebook["Mummy"].push_back("9936796296");
	phonebook["Mine"].push_back("6388195417");
	phonebook["Mine"].push_back("6391016296");

	for(auto x: phonebook)
	{
		cout<<x.first<<endl;
		print(x.second);
	}

	return 0;
}
