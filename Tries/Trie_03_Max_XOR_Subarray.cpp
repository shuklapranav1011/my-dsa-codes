
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
	}
};

class trie
{
	node*root;
public:
	trie()
	{
		root=new node();
	}

	//insert func;

	//for a 32 bit number
	void insert(int n)
	{
		node*temp = root;
		for(int i=31; i>=0;i--)
		{
			int bit = (n>>i)&1;
			//i zeros on the left of msb
			// to get right most bit

			if(bit == 0)
			{
				if(temp->left==NULL)
				{
					temp->left=new node();
				}
				temp= temp->left;
			}

			if(bit == 1)
			{
				if(temp->right==NULL)
				{
					temp->right=new node();
				}
				temp= temp->right;
			}
		}
	}

	int maxXOR(int n)
	{
		node*temp=root;
		int ans=0;
		for(int i=31; i>=0; i--)
		{
			int bit = (n>>i)&1;
			if(bit)
			{
				if(temp->left!=NULL)
				{
					temp= temp->left;
					ans = ans+ (1<<i);
				}
				else
				{
					temp= temp->right;
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					temp=temp->right;
					ans = ans+ (1<<i);
				}
				else
				{
					temp=temp->left;
				}
			}
		}
		return ans;
	}
};

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
	
	int a[]={3,10,4,25,2,8}; 

	int cXOR[6];
	cXOR[0]=a[0];

	for(auto i=1; i<6; i++)
		cXOR[i] = a[i]^cXOR[i-1];

	trie t;

	for(auto i=0; i<6; i++)
		t.insert(cXOR[i]);

	unordered_map< int,vector<int> > m;

	int maxXOR=0;
	for(auto i=0; i<6; i++)
	{
		maxXOR=max(t.maxXOR(cXOR[i]),maxXOR);
		m[maxXOR].push_back(i);
	}

	for(auto i=m[maxXOR][0]; i<m[maxXOR].size()-1;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}
