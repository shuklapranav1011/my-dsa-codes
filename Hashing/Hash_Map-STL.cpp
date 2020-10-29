#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef ONLINE_JUDGE
	//getting input from the input.txt
	freopen("intput.txt" , "r" , stdin);
	
	//writing output into output.txt
	freopen("output.txt" , "w" , stdout);
	
	#endif
	
	
	map<string, int> m;

	//insert M1
	m.insert(make_pair("Mango" , 100));

//insert M2
	pair<string,int> p;
	p.first = "Apple";
	p.second = 10;

//insert M3
	m["Banana"] = 40;


//Search

	auto it=m.find("Mango");

	if(it!=m.end())
	{
		cout<<"price of " << "Mango " << m["Mango"]<<endl;
	}
	else
		cout<<"NOT PRESENT";


//Another way to find key

	//MAP HAS A PROPERTY THAT UNIQUE KEYS CAN BE STORED ONLY ONCE

string fruit;
cin>>fruit;

  if(m.count(fruit)==1)
  {
  	cout<<m[fruit]<<" is price of fruit"<< endl;
  }

//count function returns 1: present and 0: not present

//find function returns iterator of the map map<string , int> :: iterator



for(auto x:m)
{
	cout<<x.first<<" "<<x.second<<endl;
}


	return 0;
}
