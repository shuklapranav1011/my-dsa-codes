//Unique Prefix Array

/*

words[] = ["cobra" , "dog , "dove" , "duck"]

ouptut[] = ["c" , "dog" , "dove , "du"]

Prefix has to be smallest. 
*/




#include <bits/stdc++.h>
using namespace std;

class Node{

public:
	char data;
	int cnt;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char d)
	{
		data = d;
		cnt = 1; //frequency of a particular node data
		terminal = false;
	}
};

class Trie
{
	Node* root;
	int count = 0; //number of nodes

public:
	Trie()
	{
		root = new Node('\0');
		count = 0;
	}

	void insert(char *w)
	{
		Node* temp = root;
		for(int i=0; w[i]!='\0'; i++)
		{
			char ch = w[i];
			if(temp->children.count(ch))
			{
				temp = temp->children[ch];
				temp->cnt++;
			}
			else
			{
				Node* n=new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

	bool find(char *w)
	{
		Node*temp = root;
		for(int i=0; w[i]!='\0' ; i++)
		{
			char ch= w[i];
			if(temp->children.count(ch)==0)
				return false;
			else
			{
				temp = temp->children[ch];
			}
		}
		return temp->terminal;
	}

	string unique_prefix(char*w)
	{
		Node* temp = root;
		string ans ="";
		for(int i=0; w[i]!='\0'; i++)
		{
			char ch = w[i];
			temp=temp->children[ch];
			if(temp->cnt > 1)
			{
				ans=ans+ch;
			}
			else if(temp->cnt == 1)
			{
				ans=ans+ch;
				return ans;
			}
		}
		if(temp->cnt>1 && temp->terminal == true)
			return ""; 	
	}
};


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	Trie t;
	char words[][100]={"cobra","dog","dove","duck","cobras"};

	for(int i=0;i<5;i++)
	{
		t.insert(words[i]);
	}

	return 0;
}



