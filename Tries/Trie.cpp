#include <bits/stdc++.h>
using namespace std;

class Node{

public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char d)
	{
		data = d;
		terminal = false;
	}
};

class Trie
{
	Node* root;
	int cnt;

public:
	Trie()
	{
		root = new Node('\0');
		cnt = 0;
	}

//we input different words one by one in the trie
	//we input one word 
	//then another word
//think like this and dry run
	
	void insert(char *w)
	{
		Node* temp = root;
		for(int i=0; w[i]!='\0'; i++)
		{
			char ch = w[i];
			if(temp->children.count(ch))
			{
				temp = temp->children[ch];
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
};

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	Trie t;
	char words[][100] = {"a", "hello" , "not" , "news" , "apple" , "ape" , "hi"};

	char w[10];
	cin>>w;

	for(int i=0;i<7;i++)
	{
		t.insert(words[i]);
	}


	if(t.find(w))
		cout<<"Present";
	else
		cout<<"Not Present";

	return 0;
}



